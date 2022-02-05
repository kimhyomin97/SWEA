// boj 1260 DFS¿Í BFS S2
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, v;
vector <int> tree[1001];
bool visit[1001] = {false,};

void dfs(int num){
	if(visit[num] == false){
		visit[num] = true;
		printf("%d ", num);
		for(int i=0; i<tree[num].size(); i++){
			dfs(tree[num][i]);
		}
	}
}

void bfs(int num){
	printf("%d ", num);
	visit[num] = true;
	queue<int> q;
	q.push(num);
	while(q.size() > 0){
		int now = q.front();
		q.pop();
		for(int i=0; i<tree[now].size(); i++){
			if(visit[tree[now][i]] == false){
				printf("%d ", tree[now][i]);
				visit[tree[now][i]] = true;
				q.push(tree[now][i]);
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
	dfs(v);
	for(int i=0; i<=n; i++) visit[i] = false;
	printf("\n");
	bfs(v);
	
	return 0;
} 
