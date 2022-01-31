// boj 13460 ±∏ΩΩ ≈ª√‚ 2 G1
#include <cstdio>

struct pos{
	int row;
	int col;
};

int r, c;
char map[11][11];
pos blue, red, goal;

void left(){
	while(1){
		int nr = blue.row;
		int nc = blue.col-1;
		if(map[nr][nc] == 'O'){
			
		}
		if(nc >= 0 && map[nr][nc] )
	}
}

int main(){
	scanf("%d %d", &r, &c);
	for(int i=0; i<r; i++){
		scanf("%s", map[i]);
		for(int j=0; j<c; j++){
			if(map[i][j] == 'B'){
				blue.row = i;
				blue.col = j;
			}
			if(map[i][j] == 'R'){
				red.row = i;
				red.col = j;
			}
			if(map[i][j] == 'O'){
				goal.row = i;
				goal.col = j;
			}
		} 
	}
//	for(int i=0; i<r; i++){
//		for(int j=0; j<c; j++){
//			printf("%c ", map[i][j]);
//		}
//		printf("\n");
//	}
	
	
	return 0;
} 
