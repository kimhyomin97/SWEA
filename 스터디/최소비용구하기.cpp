// boj 1916 최소비용 구하기
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct info{
	int cost;
	int start;
	int dest;
};

//bool operator < (info a, info b){
//	return a.cost > b.cost;
//}

int n, m;
vector<info> map[1001];
int st, dt; // 출발점, 도착점
bool visit[1001] = {false,}; // 온 경로를 저장하는 용도로 변경해야 된다 

int dij[1001] = {0,};
//2
//2
//1 2 10
//1 2 2
//1 2
int main(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		bool flag = true;
		for(int j=0; j<map[a].size(); j++){
			if(map[a][j].dest == b){
				if(map[a][j].cost > c){
					flag = false;
					map[a][j].cost = c;
				}
				else{
					flag = false;
				}
			}
		}
		if(flag) map[a].push_back({c, a, b});
	}
	scanf("%d %d", &st, &dt);
	
	for(int i=1; i<=n; i++) dij[i] = -1;
//	for(int i=1; i<=n; i++) dij[i] = 1e9;
	
	queue<info> q;
//	priority_queue<info> q;
	visit[st] = true;
	for(int i=0; i<map[st].size(); i++) {
		info now = map[st][i];
		dij[now.dest] = now.cost;
		q.push(now);
	}
	
	while(q.size() != 0){
		int size = q.size();
		for(int i=0; i<size; i++){
			info now = q.front();
//			info now = q.top();
			q.pop();
			for(int j=0; j<map[now.dest].size(); j++){
				info temp = map[now.dest][j];
//				if(visit[temp.dest] == false){
//					visit[temp.dest] = true;
					q.push(temp);
					if(dij[temp.dest] == -1 || dij[temp.dest] > dij[temp.start] + temp.cost){
						dij[temp.dest] = dij[temp.start] + temp.cost;
					}
//				}
			}
		}
	}
	
	printf("%d", dij[dt]);
	
	return 0;
} 
