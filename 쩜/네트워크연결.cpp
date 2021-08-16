// 백준 1922 네트워크 연결
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct info{
    int cost;
    int start;
    int end;
};
int n, m;
int ans=0;

priority_queue <info> pq;

bool operator < (info a, info b){
    return a.cost > b.cost;
}

vector <info> edge[1001];
bool visit[1001] = {false,};
void solve(){
    for(int i=0; i<edge[1].size(); i++){
        pq.push(edge[1][i]);
    }
    int len = 1;
    visit[1] = true;
    while(pq.size()!=0){
        if(len == n) break;
        info now = pq.top();
        pq.pop();
        if(visit[now.end] == false){
            ans += now.cost;
            visit[now.end] = true;
            len++;
            for(int i=0; i<edge[now.end].size(); i++){
                pq.push(edge[now.end][i]);
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edge[a].push_back({c, a, b});
        edge[b].push_back({c, b, a});
    }
    solve();
    printf("%d", ans);
    return 0;
}