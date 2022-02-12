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
queue <info> q;

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
	
//	for(int i=1; i<=v; i++) dij[i] = -1;
	memset(dij, -1, sizeof(dij));
	
	q.push({0, k});
	dij[k] = 0;
	
	while(q.size()!=0){
		info now = q.front();
		q.pop();
		for(int i=0; i<map[now.dest].size(); i++){
			info temp = map[now.dest][i];
			if(dij[temp.dest] == -1 || dij[temp.dest] > dij[now.dest] + temp.cost){
				dij[temp.dest] = dij[now.dest] + temp.cost;
				q.push({dij[temp.dest], temp.dest});
				// temp.cost가 아닌 dij[temp.dest]를 큐에 넣어주면 시간이 훨씬 단축된다 
			
			}
		}
	}
	
	for(int i=1; i<=v; i++){
		if(dij[i] == -1) printf("INF\n");
		else printf("%d\n", dij[i]);
	}
	
	return 0;
} 
