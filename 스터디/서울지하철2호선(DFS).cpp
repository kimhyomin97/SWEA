// boj 16947 서울 지하철 2호선 DFS버전
#include <cstdio>
#include <vector>
using namespace std;

int n;
vector <int> map[3001];
//vector <int> cycle;
bool cycle[3001] = {false, ;
bool visit[3001] = {false,};
int check[3001] = {0,};
int distance[3001] = {0,};

void dfs(int num, int before){
	for(int i=0; i<map[num].size(); i++){
		int offset = map[num][i];
		if(visit[offset] == false){
			visit[offset] = true;
			cycle[offset] = true;
			dfs(map[num][i], num);
			cycle[offset] = false;
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
		map[b].push_back(a);
	}
	dfs(1, 1);
	
	
	return 0;
} 
