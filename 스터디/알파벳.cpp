// boj 1987 알파벳 G4 
#include <cstdio>

int r, c;
char map[21][21];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1}; // 상 하 우  

bool visit[26] = {false,}; // a~z 방문했는지 확 
int ans = 0;

void recur(int row, int col, int cnt){
	for(int i=0; i<4; i++){
		int nr = row + dr[i];
		int nc = col + dc[i];
		if(nr >= 0 && nr < r && nc >= 0 && nc < c && visit[map[nr][nc] - 'A'] == false){
			visit[map[nr][nc] - 'A'] = true;
			recur(nr, nc, cnt+1);
			visit[map[nr][nc] - 'A'] = false;
		}
	} 
	if(cnt > ans) ans = cnt;
}

int main(){
	scanf("%d %d", &r, &c);
	for(int i=0; i<r; i++){
		scanf("%s", &map[i]);
	}
//	for(int i=0; i<r; i++){
//		for(int j=0; j<c; j++){
//			printf("%c ", map[i][j]);
//		}
//		printf("\n");
//	}
	visit[map[0][0]-'A'] = true;
	ans++;
	recur(0, 0, 1);
	 
	printf("%d", ans);
	return 0;
} 
