// boj 1753 최단경로
// priority_queue 사용 방법 
#include <cstdio>
#include <vector>
#include <queue>
#include <memory.h>
#define INF 987654321
using namespace std;

struct info {
	int cost;
	int dest;
};

int v, e, k;
vector<info> map[20001];
int dij[20001] = {0,};
priority_queue <info> pq;

bool operator < (info a, info b){
	return a.cost > b.cost;
}

int main(){
	scanf("%d %d", &v, &e);
	scanf("%d", &k);
	for(int i=0; i<e; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back({c, b});
	}
	
	for(int i=1; i<=v; i++) dij[i] = INF; // 최소비용 저장할 배열 큰값으로 초기화 
	pq.push({0, k}); // {비용 0, 시작위치} 큐에 넣어준다 
	dij[k] = 0; // 자기자신으로 가는 비용은 0 
	
	while(pq.size()!=0){
		info now = pq.top(); // 가장 작은 비용값과 노드정보를 가져온다 
		pq.pop();
		if(dij[now.dest] < now.cost) continue; // 큐에 있던 최소값이 이미 계산된 최소값보다 크다면 스킵 
		for(int i=0; i<map[now.dest].size(); i++){
			// now에 저장한 최소비용으로 갈 수 있는 노드에서 갈 수 있는 노드들의 비용을 계산한다  
			info temp = map[now.dest][i];  
			if(dij[temp.dest] > dij[now.dest] + temp.cost){
				dij[temp.dest] = dij[now.dest] + temp.cost;
				pq.push({dij[temp.dest], temp.dest});
			}
		}
	}
	
	for(int i=1; i<=v; i++){
		if(dij[i] == INF) printf("INF\n");
		else printf("%d\n", dij[i]);
	}
	
	return 0;
} 
