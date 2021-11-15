#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v;
vector<int> tree[1001];
bool visit[1001] = {false,};

void dfs(int num){
    if(visit[num] == false){
        visit[num] = true;
        printf("%d ", num);
        for(int i=0; i<tree[num].size(); i++)
        dfs(tree[num][i]);
    }
    return;
}
void bfs(int num){
    queue <int> q;
    q.push(num);
    visit[num] = true;
    printf("%d ", num);
    while(q.size() != 0){
        int front = q.front();
        q.pop();
        for(int i=0; i<tree[front].size(); i++){
            if(visit[tree[front][i]] == false){
                visit[tree[front][i]] = true;
                printf("%d ", tree[front][i]);
                q.push(tree[front][i]);
            }
        }
    }
}

int main(){
    scanf("%d %d %d", &n, &m, &v);
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for(int i=0; i<=n; i++) sort(tree[i].begin(), tree[i].end());
    // 여기 i<=n 에서 = 안넣어서 틀림... 주의
    dfs(v);
    for(int i=0; i<=n; i++) visit[i] = false;
    printf("\n");
    bfs(v);
    return 0;
}