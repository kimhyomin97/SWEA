// boj 1978 ¾ËÆÄºª
#include <cstdio>

int r, c;
char map[21][21];
bool visit[27] = {false,};
int ans = -1;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void recur(int row, int col, int num){
	for(int i=0; i<4; i++){
		int nr = row + dr[i];
		int nc = col + dc[i];
//		if(nr >= 0 && nr < r && nc >= 0 && nc < c){
//			if(visit[map[nr][nc]-'A'] == false){
//				visit[map[nr][nc]-'A'] = true;
//				recur(nr, nc, num+1);
//				visit[map[nr][nc]-'A'] = false;
//			}
//		}
		if(nr >= r || nr < 0 || nc >= c || nc < 0) continue;
		if(visit[map[nr][nc]-'A'] == true) continue;
		else{
			visit[map[nr][nc]-'A'] = true;
			recur(nr, nc, num+1);
			visit[map[nr][nc]-'A'] = false;
		}
	}
	if(ans < num) ans = num;
	return;
}

int main(){
	scanf("%d %d", &r, &c);
	for(int i=0; i<r; i++){
		scanf("%s", map[i]);
//		for(int j=0; j<c; j++){
//			scanf("%c", &map[i][j]);
//		}
	}
	visit[map[0][0]-'A'] = true;
	recur(0, 0, 0);
	printf("%d", ans+1);
	return 0;
} 
