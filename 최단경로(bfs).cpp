// 백준 최단경로 문제 bfs로 시도
#include <cstdio>
#include <vector>
using namespace std;

int v, e, s;
struct info{
	int cost;
	int dest;
};
vector<info>edge[20001];
int step[20001][20001];

void bfs(int num){
	for(int i=0; i<edge[num].size(); i++){
		
	}
}

int main(){
	scanf("%d%d%d",&v,&e,&s);
	for(int i=0; i<e; i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		edge[a].push_back({b,c});
	}
	bfs(s);
	
	return 0;
} 
