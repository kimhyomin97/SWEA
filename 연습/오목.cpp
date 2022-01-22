// boj 2615 오목
#include <cstdio>

int map[19][19];

// dir : 0~7 12시부터 시계방향 
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int win_color = 0;
int win_row = 20;
int win_col = 20;

void recur(int row, int col, int color, int dir, int cnt){
	// row, col, 흑/백, 방향, 연속횟수 
	if(cnt == 5){
		int nr = row + dr[dir];
		int nc = col + dc[dir];
		if(nr >= 0 && nr < 19 && nc >= 0 && nc < 19 && map[nr][nc] == color){
			return;
		}
		else{
			int r_nr = row;
			int r_nc = col;
			for(int i=0; i<5; i++){
				r_nr -= dr[dir];
				r_nc -= dc[dir];
			}
			if(r_nr >= 0 && r_nr < 19 && r_nc >= 0 && r_nc < 19 && map[r_nr][r_nc] == color){
				return;
			}
		}
		win_color = color;
		if(col < win_col){
			win_row = row;
			win_col = col;
		}
		else if(col == win_col){
			if(row < win_row) win_row = row;
		}
	}
	if(dir == -1){
		for(int i=0; i<8; i++){
			int nr = row + dr[i];
			int nc = col + dc[i];
			if(nr >= 0 && nr < 19 && nc >= 0 && nc < 19 && map[nr][nc] == color){
				recur(nr, nc, color, i, cnt+1);
			}
		}
	}
	else{
		int nr = row + dr[dir];
		int nc = col + dc[dir];
		if(nr >= 0 && nr < 19 && nc >= 0 && nc < 19 && map[nr][nc] == color){
			recur(nr, nc, color, dir, cnt+1);
		}
	}
}

int main(){
	for(int i=0; i<19; i++){
		for(int j=0; j<19; j++){
			scanf("%d", &map[i][j]);
		}
	}
	
	for(int i=0; i<19; i++){
		for(int j=0; j<19; j++){
			if(map[i][j] != 0){	
				recur(i, j, map[i][j], -1, 1);	
			}
		}
	}
	if(win_color == 0){
		printf("0");
	}
	else{
		printf("%d\n", win_color);
		printf("%d %d", win_row+1, win_col+1);
	}
	
	return 0;
} 
