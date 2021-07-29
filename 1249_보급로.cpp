#include <stdio.h>

int map[100][100];
bool visit[100][100];
int step[100][100];

int num;
int res = 100000000;
void dfs(int row, int col, int sum){
	printf("%d %d %d \n", row, col, sum);
	if(row == num-1 && col == num-1){
		if(res > sum) res = sum;
		return;
	}
	if(row < 0 || row >= num || col < 0 || col >= num || visit[row][col] == true)return;
	if(step[row][col] < sum) return;
	else{
		sum += map[row][col];
//		visit[row][col] = true;
		step[row][col] = sum;
		dfs(row+1, col, sum);
		dfs(row-1, col, sum);
		dfs(row, col+1, sum);
		dfs(row, col-1, sum);
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i=0; i<t; i++){		
		scanf("%d", &num);
		for(int i=0; i<num; i++){
			for(int j=0; j<num; j++){
				scanf("%1d", &map[i][j]);
				step[i][j] = -1;
			}
		}
//		printf("\n");
//		for(int i=0; i<num; i++){
//			for(int j=0; j<num; j++){
//				printf("%d ", map[i][j]);
//			}
//			printf("\n");
//		}
//		map = {0,};
		
		dfs(0,0,0);
		printf("#%d %d\n", i+1, res);
		for(int i=0; i<num; i++){
			for(int j=0; j<num; j++){
				visit[i][j] = false;
			}
		}
		res = 100000000;
	}
	
	return 0;
}

