// 이 문제는 swea가 아니라 백준에 있는 문제 
#include <cstdio>
#include <vector>
using namespace std;

int n, m;
//int computer[101];
vector <int> computer[101];
bool visit[101] = {false,};
int res = 0;

void dfs(int num){
//	visit[num] = true;
//	for(int i=0; i<computer[num].size();i++){
//		if(visit[computer[num][i]] == false){
//			res++;
//			dfs(computer[num][i]);
//		}
//	}
	if(visit[num] == true) return;
	else{
		res++;
		visit[num] = true;
		for(int i=0; i<computer[num].size(); i++){
			dfs(computer[num][i]);
		}
	}
}

int main(){
	scanf("%d", &n);
//	for(int i=1; i<=n; i++){
//		computer[i].push_back(i);
//	}
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		computer[a].push_back(b);
		computer[b].push_back(a);
	}
	dfs(1);
	printf("%d", res-1);
	
	return 0;
} 

