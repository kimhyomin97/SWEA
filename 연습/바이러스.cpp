// 백준 2606 바이러스
#include <cstdio>
#include <vector>

using namespace std;
int n, e;
vector<int> edge[101];
bool visit[101] = {false, };
int ans = -1;

void dfs(int num){
	if(visit[num] == true) return;
	visit[num] = true;
	ans++;
	for(int i=0; i<edge[num].size(); i++){
		dfs(edge[num][i]);
	}
}

int main(){
	scanf("%d", &n);
	scanf("%d", &e);
	for(int i=0; i<e; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(1);
	printf("%d", ans);
	return 0;
} 
