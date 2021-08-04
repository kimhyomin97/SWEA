// 백준 14502 연구소
#include <cstdio>
#include <queue>
using namespace std;

int n, m;
int lab[8][8];
struct position {
	int row;
	int col;
};
queue <position> virus;
int ans = 0;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int count(){
	int cnt=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(lab[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

void bfs(){
	int temp[n][m];
	queue<position> q;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			temp[i][j] = lab[i][j];
			if(temp[i][j] == 2) q.push({i,j});
		}
	}
	while(q.size()!= 0){
		position now = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int nr = now.row+dr[i];
			int nc = now.col+dc[i];
			if(nr < 0 || nr >= n || nc < 0 || nc >= m || temp[nr][nc] == 1 || temp[nr][nc] == 2){
				continue;
			}
			else{
				temp[nr][nc] = 2;
				q.push({nr, nc});
			}
		}
	}
	int cnt = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(temp[i][j] == 0) cnt++;
		}
	}
	if(cnt > ans) ans = cnt;
}

void dfs(int len){
	if(len == 3) {
		bfs();
		return;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(lab[i][j] == 0){
				lab[i][j] = 1;
				dfs(len+1);
				lab[i][j] = 0;
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &lab[i][j]);
			if(lab[i][j] == 2) virus.push({i, j});
		}
	}
	
	dfs(0);
	printf("%d", ans);
} 
