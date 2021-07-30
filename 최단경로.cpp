// 이 문제는 swea가 아닌 백준에 있는 문제
// 이차원 배열이 아닌 일차원 배열로 우선 시도해봤다 
#include <cstdio>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int v, e, s;
struct info{
	int cost;
	int dest;
};

vector <info> edge[20001];
int step[20001];
bool operator < (info a, info b){
	return a.cost  > b.cost;
}
priority_queue <info> pq;

int main(){
	scanf("%d%d%d", &v, &e, &s);
	for(int i=0; i<e; i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		edge[a].push_back({c,b});
	}
	for(int i=1; i<=v; i++){
		step[i] = -1;
	}
//	memset(step, -1, sizeof(step));
	pq.push({0, s});
	step[s] = 0;
	while(pq.size() != 0){
		info now = pq.top();
		pq.pop();
		for(int i=0; i<edge[now.dest].size(); i++){
			info temp = edge[now.dest][i];
			if(step[temp.dest] == -1 || step[temp.dest] > step[now.dest] + temp.cost){
				step[temp.dest] = step[now.dest] + temp.cost;
				pq.push(temp);
			}
		}
	}
	for(int i=1; i<=v; i++){
		if(step[i] == -1) printf("INF\n");
		else printf("%d\n", step[i]);
	}
	
	return 0;
}
