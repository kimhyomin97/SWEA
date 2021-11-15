#include <cstdio>
#include <queue>
using namespace std;
struct pos{
	int row;
	int col;
};
int main(){
	int n;
	scanf("%d", &n);
	int map[100][100];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &map[i][j]);
		}
	}
	queue <pos> start;
	start.push({1, 1});
	long long ans=0;
	while(start.size() != 0){
		ans++;
		pos now = start.front();
		start.pop();
		int offset = map[now.row][now.col];
		if(offset == 0) continue;
		if(offset + now.row < n){
			start.push({offset + now.row, now.col});
		} 
		if(offset + now.col < n){
			start.push({now.row, offset+now.col});
		}
	}
	printf("%lld", ans);
	return 0;
}
