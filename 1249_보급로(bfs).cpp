#include <stdio.h>
#include <queue>
using namespace std;

int map[100][100];
int visit[100][100] = {0,};
int res = 90000;
int num;
//void bfs(int row, int col, int sum, int tc){
//	if(row == num-1 && col == num-1){
//		if(res > sum) res = sum;
//		return;
//	}
//	if(sum > num * num) return;
//	if(row < 0 || row >= num || col < 0 || col >= num || visit[row][col] == -1) return;
//	else{
//		sum += map[row][col];
//		visit[row][col] = sum;
//		bfs(row+1, col, sum, tc);
//		bfs(row-1, col, sum, tc);
//		bfs(row, col+1, sum, tc);
//		bfs(row, col-1, sum, tc);
//	}
//}
struct pos {
	int row;
	int col;
};

void bfs(int sum){
	queue <pos> q;
	
	// queue를 사용해서 구현해보자... 
}

int main(){
	int t;
	scanf("%d", &t);
	for(int test=1; test<=t; test++){
		scanf("%d", &num);
		for(int i=0; i<num; i++){
			for(int j=0; j<num; j++){
				scanf("%1d", &map[i][j]);
				visit[i][j] = -1;
			}
		}
//		for(int i=0; i<num; i++){
//			for(int j=0; j<num; j++){
//				printf("%d ", map[i][j]);
//			}
//			printf("\n");
//		}
//		bfs(0, 0, 0, test);	
		bfs(0);
		printf("#%d %d\n", test, res);
		res = 90000;
	}
	
	return 0;
}
