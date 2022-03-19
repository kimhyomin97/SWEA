// boj 17396 ¹éµµ¾î
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
	int n, m;
	scanf("%d %d", &n, &m);
	int list[n];
	for(int i=0; i<n; i++){
		scanf("%d", &list[i]);
	}
	vector<info> map[n];
	for(int i=0; i<m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(b != n-1 && list[b]==1) continue;
		map[a].push_back({c, b});
		map[b].push_back({c, a});
	}
	
	long long dij[n+1];
	for(int i=0; i<=n; i++) dij[i] = 9223372036854775807;
	priority_queue <info> pq;
	pq.push({0, 0});
	dij[0] = 0;
	while(pq.size() != 0){
		info now = pq.top();
		pq.pop();
		int size = map[now.dest].size();
		if(dij[now.dest] < now.cost) continue;
		for(int i=0; i<size; i++){
			info temp = map[now.dest][i];
			if(temp.dest != n-1 && list[temp.dest]==1);
			else{
				if(dij[temp.dest] > dij[now.dest] + temp.cost){
					dij[temp.dest] = dij[now.dest] + temp.cost;
					pq.push({dij[temp.dest], temp.dest});
				}
			}
		}
	}
	if(dij[n-1]==9223372036854775807) printf("-1");
	else printf("%lld", dij[n-1]);
	return 0;
} 
