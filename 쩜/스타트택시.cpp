// 백준 19238 스타트 택시
#include <cstdio>
#include <queue>
using namespace std;

int n, m, remain;
int map[21][21];
int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};
bool flag = true;

struct pos{
	int row;
	int col;
};
pos start;

struct dest{
	int st_row;
	int st_col;
	int de_row;
	int de_col;
	bool visit = false;
};

dest list[400];

pos goal[403];
bool goal_visit[403] = {false,};

int goal_cnt=0;

void move_goal(int index){
	// 골인지점까지 이동 
	int cnt=0;
	bool visit[21][21] = {false,};
	queue <pos> q;
	q.push(start);
	while(q.size()!=0){
		cnt++;
		remain--;
		int len = q.size();
		for(int i=0; i<len; i++){
			pos now = q.front();
			q.pop();
			for(int j=0; j<4; j++){
				int nr = now.row + dr[j];
				int nc = now.col + dc[j];
				if(nr < 1 || nr > n || nc < 1 || nc > n || visit[nr][nc] == true || map[nr][nc] == 1) continue;
				else{
					if(nr == goal[index].row && nc == goal[index].col){
						start.row = nr;
						start.col = nc;
						remain+=cnt*2;
						goal_cnt++;
						return;
					}
					visit[nr][nc] = true;
					q.push({nr, nc});
				}
			}
		}
		
		if(remain==0) {
			flag = false;
			return;
		}
	}
}

void bfs(){
	bool visit[21][21] = {false,};
	queue <pos> q;
	q.push(start);
	while(q.size()!=0){
		remain--;
		int len = q.size();
		for(int i=0; i<len; i++){
			pos now = q.front();
			q.pop();
			for(int j=0; j<4; j++){
				int nr = now.row + dr[j];
				int nc = now.col + dc[j];
				if(nr < 1 || nr > n || nc < 1 || nc > n || visit[nr][nc] == true || map[nr][nc] == 1) continue;
				else{
					if(map[nr][nc] != 0){
						if(goal_visit[map[nr][nc]] == false){
							start.row = nr;
							start.col = nc;
							goal_visit[map[nr][nc]] = true;
							move_goal(map[nr][nc]);
							return;
						}
					}
					visit[nr][nc] = true;
					q.push({nr, nc});
				}
			}
		}
		
		if(remain==0) {
			flag = false;
			return;
		}
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &remain);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			scanf("%d", &map[i][j]);			
		}
	}
	scanf("%d%d", &start.row, &start.col);
	
	for(int i=2; i<m+2; i++){
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
//		list[i] = {a, b, c, d};
//		list[i].st_row = a;
//		list[i].st_col = b;
//		list[i].de_row = c;
//		list[i].de_col = d;
		map[a][b] = i;
		goal[i] = {c, d};
	}
//	int cnt = 0;
	while(goal_cnt != m){
		bfs();
		if(flag == false) {
			printf("-1");
			break;
		}
	}
	if(flag == true) printf("%d", remain);
	
	return 0;
}
