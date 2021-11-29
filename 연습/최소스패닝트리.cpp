// 1197 최소 스패닝 트리
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct info{
	long long cost;
	int dest;
};
bool operator < (info a, info b){
	return a.cost > b.cost;
}

int main(){
	int v, e;
	scanf("%d %d", &v, &e);
	vector <info> map[v+1];
	bool visit[v+1] = {false,};
	for(int i=0; i<e; i++){
		int a, b;
		long long c;
		scanf("%d %d %lld", &a, &b, &c);
		map[a].push_back({c, b});
		map[b].push_back({c, a});
	}
	priority_queue <info> pq;
	visit[1] = true;
	for(int i=0; i<map[1].size(); i++) pq.push(map[1][i]);
	int len = 1;
	long long ans = 0;
	while(len != v){
		info now = pq.top();
		pq.pop();
		if(visit[now.dest] == true) continue;
		ans += now.cost;
		visit[now.dest] = true;
		len++; 
		for(int i=0; i<map[now.dest].size(); i++) {
			pq.push(map[now.dest][i]);
		}
	}
	printf("%lld", ans);
	return 0;
} 
