// ¹Ì·Î1
#include <cstdio>
#include <queue>
using namespace std;
int ans = 0;
int test;
struct position{
	int row;
	int col;
};
position start = {1, 1};
position dest = {13, 13};
int game[16][16];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int visit[16][16];

void solve(){
	queue <position> q;
	q.push(start);
	while(q.size()!=0){
		position now = q.front();
		q.pop();
		if(game[now.row][now.col] == 3){
			ans = 1;
			break;
		}
		for(int i=0; i<4; i++){
			int nr = now.row + dr[i];
			int nc = now.col + dc[i];
			if(visit[nr][nc] != test && game[nr][nc] != 1){
				visit[nr][nc] = test;
				q.push({nr, nc});
			}
		}
	}	
}

int main(){
	for(int t=1; t<=10; t++){
		scanf("%1d", &test);
		for(int i=0; i<16; i++){
			for(int j=0; j<16; j++){
				scanf("%1d", &game[i][j]);
			}
		}
		
		solve();
		
		printf("#%d %d\n", t, ans);
		ans = 0;
	}
	
	return 0;
}

