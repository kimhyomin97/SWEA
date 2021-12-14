// boj 1520 내리막 길
#include <cstdio>

int col, row;
int map[500][500];
//bool visit[500][500] = {false,};
int dp[500][500];

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int ans = 0;

int recur(int r, int c){
	if(r == row-1 && c == col-1){
		return 1;
	}
	if(dp[r][c] != -1) return dp[r][c];
	dp[r][c] = 0;
	for(int i=0; i<4; i++){
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(nr >= 0 && nr < row && nc >= 0 && nc < col){
			if(map[nr][nc] < map[r][c]){
				dp[r][c] = dp[r][c] + recur(nr, nc);
			}
		}
//		if(nr >= 0 && nr < row && nc >= 0 && nc < col && visit[nr][nc] == 0){
//			if(map[r][c] > map[nr][nc]){
//				visit[nr][nc] = true;
//				recur(nr, nc);
//				visit[nr][nc] = false;
//			}
//		}
	}
	return dp[r][c];
}

int main(){
	scanf("%d %d", &row, &col);
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			scanf("%d", &map[i][j]);
			dp[i][j] = -1;
		}
	}
	ans = recur(0, 0);
	printf("%d", ans);
	return 0;
} 
