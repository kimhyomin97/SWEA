// 백준 2458 키순서
#include <cstdio>
#include <vector>
using namespace std;

int n, m;
vector <int> edge[501];
vector <int> edge_rev[501];

bool visit[501] = {false,};
int len[501] = {0,};
int len_rev[501] = {0, };
int ans=0;

void reset(){
    for(int i=1; i<=n; i++) visit[i] = false;
}

void count(int index, int recur){
    for(int i=0; i<edge[recur].size(); i++){
        // printf("recur : %d\n", edge[recur][i]);
        if(visit[edge[recur][i]] == false){
            len[index]++;
            visit[edge[recur][i]] = true;
            count(index, edge[recur][i]);
            // visit[edge[recur][i]] = false;
        }
    }
}

void count_rev(int index, int recur){
    for(int i=0; i<edge_rev[recur].size(); i++){
        // printf("recur %d : %d\n", index, edge_rev[recur][i]);
        if(visit[edge_rev[recur][i]] == false){
            len_rev[index]++;
            visit[edge_rev[recur][i]] = true;
            count_rev(index, edge_rev[recur][i]);
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        // a보다 b가 크다
        edge[a].push_back(b);
        edge_rev[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        count(i, i);
        reset();
        count_rev(i, i);
        reset();
        if(len[i] + len_rev[i] == n-1) ans++;
    }

    printf("%d", ans);
    return 0;
}