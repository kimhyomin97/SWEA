// boj 6497 Àü·Â³­
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct info{
	int cost;
	int start;
	int dest;
};

bool operator < (info a, info b){
	return a.cost > b.cost;
}

int main(){
	while(1){
		int m, n;
		scanf("%d %d", &m, &n);
		if(m == 0 && n == 0) break;
		vector <info> map[m];
		bool visit[m] = {false, };
		
		int sum = 0;
		for(int i=0; i<n; i++){
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			map[x].push_back({z, x, y});
			map[y].push_back({z, y, x});
			sum += z;
		}
		priority_queue <info> pq;
		int ans = 0;
		for(int i=0; i<map[0].size(); i++){
			pq.push({map[0][i].cost, map[0][i].start, map[0][i].dest});
		}
		visit[0] = true;
		while(pq.size()){
			info now = pq.top();
			pq.pop();
			if(visit[now.dest] == false){
				visit[now.dest] = true;
				ans += now.cost;
				for(int i=0; i<map[now.dest].size(); i++){
					pq.push(map[now.dest][i]);
				}
			}
		}
		printf("%d\n", sum-ans);
	}
	
	
	return 0;
} 
