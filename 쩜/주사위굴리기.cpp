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
			
		}
		else if(num == 2){
			
		}
		else if(num == 3){
			
		}
		else if(num == 4){
			
		}
	}
	
	return 0;
} 
