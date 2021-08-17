// 백준 2252 줄 세우기
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, m;

vector <int> edge[32000];
int len[32000] = {0,};
bool visit[32000] = {false,};

void solve(){
    for(int j=0; j<n; j++){
        int min = 100001, index;
        for(int i=1; i<=n; i++){
            if(visit[i] == true) continue;
            if(len[i] < min){
                min = len[i];
                index = i;
            }
        }
        visit[index] = true;
        printf("%d ", index);
        for(int i=0; i<edge[index].size(); i++){
            len[edge[index][i]]--;
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        edge[a].push_back(b);
        len[b]++;
    }
    solve();
    return 0;
}