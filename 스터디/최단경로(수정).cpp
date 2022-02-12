// boj 1753 최단경로
#include <cstdio>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

struct info {
	int cost;
	int dest;
};

int v, e, k;
vector<info> map[20001];
int dij[20001] = {0,};
bool visit[20001] = {false,};

int main(){
	scanf("%d %d", &v, &e);
	scanf("%d", &k);
	for(int i=0; i<e; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		bool flag = true;
		for(int j=0; j<map[a].size(); j++){
			if(map[a][j].dest == b){
				flag = false;
				if(map[a][j].cost > c) map[a][j].cost = c;
			}
		}
		if(flag) map[a].push_back({c, b});
	}
	
	for(int i=1; i<=v; i++) dij[i] = -1;
	
	dij[k] = 0;
	visit[k] = true;
	for(int i=0; i<map[k].size(); i++) dij[map[k][i].dest] = map[k][i].cost;
	
	for(int i=1; i<=v; i++){
		int min = -1;
		int index = k;
		for(int j=1; j<=v; j++){ 
//			방문하지 않았던 노드 중에서 최소 비용을 갖는 정점을 찾는다 
//			이부분때문에 O(n^2)이 된다 
			if(visit[j]==false && (min == -1 || dij[j] < min)) {
				min = dij[j];
				index = j;
			}
		}
		visit[index] = true; // 노드에 방문처리를 해준다 
		for(int j=0; j<map[index].size(); j++){
//			찾은 노드에서 다른 노드로 가는 최소 비용을 계산한다  
			info temp = map[index][j];
			if(dij[temp.dest] == -1 || dij[temp.dest] > dij[index] + temp.cost){
				dij[temp.dest] = dij[index] + temp.cost;
				// 최소 비용을 갱신해준다 
			}
		}
	}
	
	for(int i=1; i<=v; i++){
		if(dij[i] == -1) printf("INF\n");
		else printf("%d\n", dij[i]);
	}
	
	return 0;
} 
