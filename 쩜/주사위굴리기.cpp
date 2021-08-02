// 백준 14499 주사위 굴리기

#include <cstdio>

int r, c, st_r, st_c, k;
int game[21][21];

int main(){
	scanf("%d%d%d%d%d", &r, &c, &st_r, &st_c, &k);
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			scanf("%d", &game[i][j]);
		}
	}
	for(int i=0; i<k; i++){
		int num;
		scanf("%d", &num);
		if(num == 1){
			// 동 
		}
		else if(num == 2){
			// 서
			 
		}
		else if(num == 3){
			// 북 
			 
		}
		else if(num == 4){
			// 남 
			 
		}
	}
	
	return 0;
} 
