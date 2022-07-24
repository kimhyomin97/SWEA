//test
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
 
struct info{
	int cost;
	int dest;
};

bool operator < (info a, info b){
	return a.cost > b.cost;
}

int main(){
	int v, e;
	scanf("%d %d", &v, &e);
	int start;
	scanf("%d", &start);
	
	vector<info> map[20001];
	
	for(int i=0; i<e; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back({c, b});
	}
	
	int dij[20001] = {0, };
	
	for(int i=0; i<=v; i++) dij[i] = 987654321;
	
	priority_queue <info> pq;
	
	pq.push({0, start});
	dij[start] = 0;
	
	while(pq.size() != 0){
		info now = pq.top();
		pq.pop();
		for(int i=0; i<map[now.dest].size(); i++){
			info temp = map[now.dest][i];
			if(dij[temp.dest] > dij[now.dest] + temp.cost){
				dij[temp.dest] = dij[now.dest] + temp.cost;
				pq.push({dij[temp.dest], temp.dest});
			}
		}
	}
	
	for(int i=1; i<=v; i++){
		if(dij[i] == 987654321) printf("INF\n");
		else printf("%d\n", dij[i]);
	}
	
	return 0;
}
