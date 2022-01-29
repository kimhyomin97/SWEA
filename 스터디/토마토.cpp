// boj 7576 ≈‰∏∂≈‰
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct pos{
	int row;
	int col;
};
int n, m;
queue <pos> tomato;
int map[1000][1000];
int dr[4] = {1, -1, 0 ,0};
int dc[4] = {0, 0, 1, -1};
int ans = 0;

int main(){	
	scanf("%d %d", &n, &m);
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 1) {
				tomato.push({i, j});
			}
		}
	}
	if(tomato.size() == n*m){
		printf("0");
		return 0;
	}
	while(tomato.size() != 0){
		int size = tomato.size();
		for(int i=0; i<size; i++){
			pos now = tomato.front();
			tomato.pop();
			for(int j=0; j<4; j++){
				int nr = now.row + dr[j];
				int nc = now.col + dc[j];
				if(nr >= 0 && nr < m && nc >= 0 && nc < n && map[nr][nc] == 0){
					map[nr][nc] = 1;
					tomato.push({nr, nc});
				}
			}
		}
		ans++;
	}
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(map[i][j] == 0) {
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d", ans-1);
	
	return 0;
} 
