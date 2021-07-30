#include <stdio.h>
#include <queue>
using namespace std;

int t;
int num;
int map[101][101];
int step[101][101];

int d_r[4] = {1,-1,0,0};
int	d_c[4] = {0,0,1,-1};

struct info{
	int row;
	int col;
};

queue <info> q;


void bfs(){
	q.push({0,0});
	step[0][0] = 0;
	while(q.size()!=0){
		info now = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int new_r = now.row + d_r[i];
			int new_c = now.col + d_c[i];
			if(step[new_r][new_c] == -1 || step[new_r][new_c] > step[now.row][now.col] + map[new_r][new_c]){
				step[new_r][new_c] = step[now.row][now.col] + map[new_r][new_c];
				q.push({new_r, new_c});
			}
		}
	}
}

int main(){
	scanf("%d", &t);
	for(int i=1; i<=t; i++){
		scanf("%d", &num);
		for(int i=0; i<num; i++){
			for(int j=0; j<num; j++){
				scanf("%1d", &map[i][j]);
				step[i][j] = -1;
			}
		}
		bfs();
		printf("#%d %d\n", i, step[num-1][num-1]);
	}
	
	return 0;
}
















//#include <stdio.h>
//#include <queue>
//#include <iostream>
//using namespace std;
//
//int map[100][100];
//int visit[100][100] = {0,};
//int res = 90000;
//int step[100][100];
//int num;
//int drow[4] = {1, -1, 0, 0};
//int dcol[4] = {0, 0, 1, -1};
//
//struct pos {
//	int row;
//	int col;
//};
//
//void bfs(int sum, int tc){
//	queue <pos> q;
//	
//	visit[0][0] = tc;
//	step[0][0] = 0;
//	
//	q.push({0,0});
//	while(q.size() != 0){
//		pos temp = q.front();
//		q.pop();
//		for(int i=0; i<4; i++){
//			int new_r = temp.row + drow[i];
//			int new_c = temp.col + dcol[i];
//			if(new_r < 0 || new_r >= num || new_c < 0 || new_c >= num) continue;
//			else{
////				if(visit[new_r][new_c] != tc || )
//				if(step[new_r][new_c] > step[temp.row][temp.col] + map[new_r][new_c]){
//					step[new_r][new_c] = step[temp.row][temp.col] + map[new_r][new_c];
//					q.push({new_r, new_c});
//				}
//			}
//		}
//	}
//	res = step[num-1][num-1];
//	// queue를 사용해서 구현해보자... 
//}
//
//int main(){
//	int t;
//	scanf("%d", &t);
//	for(int test=1; test<=t; test++){
//		scanf("%d", &num);
//		for(int i=0; i<num; i++){
//			for(int j=0; j<num; j++){
//				scanf("%1d", &map[i][j]);
////				visit[i][j] = -1;
//				step[i][j] = 90000;
//			}
//		}
////		for(int i=0; i<num; i++){
////			for(int j=0; j<num; j++){
////				printf("%d ", map[i][j]);
////			}
////			printf("\n");
////		}
////		bfs(0, 0, 0, test);	
//		bfs(0, test);
//		printf("#%d %d\n", test, res);
//		res = 90000;
//	}
//	
//	return 0;
//}
