// boj 1916 최소비용 구하기
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct info{
	int cost;
	int dest;
};

int n, m;
vector<info> map[1001];
int st, dt;
queue<info> q;
int dij[1001] = {0,};

int main(){
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		bool flag = true;
		// 최소값만 저장하는 경우를 줄일 수 있을듯 // 이부분 없으면 시간초과가 나온다 
		for(int j=0; j<map[a].size(); j++){
			if(map[a][j].dest == b){
				flag = false;
				if(map[a][j].cost > c){
					map[a][j].cost = c;
				}
			}
		}
		if(flag) map[a].push_back({c, b});
	}
	scanf("%d %d", &st, &dt);
	for(int i=0; i<=n; i++) dij[i] = -1;
	
	q.push({0, st});
	dij[st] = 0;
	while(q.size() != 0){
		info now = q.front();
		q.pop();
		for(int i=0; i<map[now.dest].size(); i++){
			info offset = map[now.dest][i];
			
			if(dij[offset.dest] == -1 || dij[offset.dest] > offset.cost + dij[now.dest]){
				dij[offset.dest] = offset.cost + dij[now.dest];
				q.push({offset.cost, offset.dest});
			}
		}
	}
	printf("%d", dij[dt]);
	
	return 0;
} 
// https://youngtoad.tistory.com/22 코드 비교해볼만한 사이트 
