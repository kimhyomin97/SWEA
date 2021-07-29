#include <stdio.h>
int map[4][4];
bool visit[4][4] = {false,};
int check[10000000] = {0,};
int res = 0;
void dfs(int row, int col, int sum, int cnt, int tc){
	if(cnt == 7) {
		if(check[sum] != tc){
			check[sum] = tc;
			res++;
		}
		return;
	}
	if(row < 0 || row >= 4 || col < 0 || col >= 4) return;
	else{
		int temp = 1;
		for(int i=0; i<cnt; i++) temp *= 10;
		sum += map[row][col] * temp;
		if(row+1 < 4) dfs(row+1, col, sum, cnt+1, tc);
		if(row-1 >= 0) dfs(row-1, col, sum, cnt+1, tc);
		if(col+1 <4) dfs(row, col+1, sum, cnt+1, tc);
		if(col-1 >= 0) dfs(row, col-1, sum, cnt+1, tc);
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i=1; i<=t; i++){
		for(int j=0; j<4; j++){
			for(int k=0; k<4; k++){
				scanf("%1d", &map[j][k]);
			}
		}
//		for(int j=0; j<4; j++){
//			for(int k=0; k<4; k++){
//				printf("%d", map[j][k]);
//			}
//			printf("\n");
//		}
		for(int j=0; j<4; j++){
			for(int k=0; k<4; k++){
				dfs(j,k, 0, 0, i);
			}
		}
		printf("#%d %d\n",i ,res);
	} 
	
	return 0;
}
