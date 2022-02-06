// boj 16947 서울 지하철 2호선 DFS버전
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n;
vector <int> map[3001];
int count[3001] = {0,};
bool flag = false;
vector <int> cycle;
int ans[3001] = {0,};
bool visit[3001] = {false,}; 

void dfs(int num, int before, int cnt){
	if(count[num] != 0){
		flag = true;
		for(int i=1; i<=n; i++){
			if(count[i] >= count[num] && count[i] < cnt){
				cycle.push_back(i);
			}
		}
		return;
	}
	count[num] = cnt;
	for(int i=0; i<map[num].size(); i++){
		if(flag == true) return;
		int offset = map[num][i];
		if(offset != before){
			dfs(offset, num, cnt+1);
		}
	}
	count[num] = -1;
}

void bfs(){
	queue <int> q;
	for(int i=0; i<cycle.size(); i++) q.push(cycle[i]);
	int cnt = 1;
	while(q.size() != 0){
		int size = q.size();
		for(int j=0; j<size; j++){
			int now = q.front();
			q.pop();
			for(int i=0; i<map[now].size(); i++){
				int offset = map[now][i];
				if(visit[offset] == false){
					visit[offset] = true;
					ans[offset] = cnt;
					q.push(offset);
				}
			}
		}
		cnt++;
	}
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
		map[b].push_back(a);
	}
	dfs(1, 1, 1); // cycle vector에 싸이클 리스트 등록
	for(int i=0; i<cycle.size(); i++) visit[cycle[i]] = true;
	bfs(); // 싸이클과의 거리 계산 
	for(int i=1; i<=n; i++) printf("%d ", ans[i]);
	return 0;
} 
