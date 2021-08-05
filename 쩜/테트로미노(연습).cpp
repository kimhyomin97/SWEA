// 백준 14500 테트로미노
#include <cstdio>

int n, m;
int map[500][500];
bool visit[500][500] = {false,};
int dr[4] = {1, -1, 0 ,0};
int dc[4] = {0, 0, 1, -1};
int ans = 0;
int exr1[4] = {0, 0, 1, 0};
int exc1[4] = {0, 1, 0, -1};

int exr2[4] = {0, -1, 0, 1};
int exc2[4] = {0, 0, 1, 0};

int exr3[4] = {0, -1, 0, 0};
int exc3[4] = {0, 0, 1, -1};

int exr4[4] = {0, -1, 1, 0};
int exc4[4] = {0, 0, 0, -1};

void recur(int len, int sum, int row, int col){
	if(len == 4) {
		if(sum > ans) ans = sum;
		return;
	}
	if(len == 0){
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				visit[i][j] = true;
				recur(len+1, map[i][j], i, j);
				visit[i][j] = false;
			}
		}
	}
	else{
		for(int i=0; i<4; i++){
			int nr = row+dr[i];
			int nc = col+dc[i];
			if(nr < 0 || nr >= n || nc < 0 || nc >= m || visit[nr][nc] == true) continue;
			visit[nr][nc] = true;
			recur(len+1, sum+map[nr][nc], nr, nc);
			visit[nr][nc] = false;
		}
	}
}

int cal(int r, int c){
	int sum = 0;
	int sum2 = 0;
	int sum3 = 0;
	int sum4 = 0;
	for(int i=0; i<4; i++){
		int nr = r+exr1[i];
		int nc = c+exc1[i];
		if(nr < 0 || nr >= n || nc < 0 || nc >= m){
			break;
		}
		sum += map[nr][nc];
	}
	for(int i=0; i<4; i++){
		int nr = r+exr2[i];
		int nc = c+exc2[i];
		if(nr < 0 || nr >= n || nc < 0 || nc >= m){
			break;
		}
		sum2 += map[nr][nc];
	}
	for(int i=0; i<4; i++){
		int nr = r+exr3[i];
		int nc = c+exc3[i];
		if(nr < 0 || nr >= n || nc < 0 || nc >= m){
			break;
		}
		sum3 += map[nr][nc];
	}
	for(int i=0; i<4; i++){
		int nr = r+exr4[i];
		int nc = c+exc4[i];
		if(nr < 0 || nr >= n || nc < 0 || nc >= m){
			break;
		}
		sum4 += map[nr][nc];
	}
	int max = sum;
	if(sum2 > max) max = sum2;
	if(sum3 > max) max = sum3;
	if(sum4 > max) max = sum4;
	return max;
}

void ex(){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int ex_num = cal(i,j);
			if(ex_num > ans) ans = ex_num;
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &map[i][j]);
		}
	}
	
	recur(0, 0, 0, 0);
	ex();
	printf("%d", ans);
	return 0;
} 
