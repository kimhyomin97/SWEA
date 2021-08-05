// น้มุ 3190 น์
#include <cstdio>
#include <queue>
using namespace std;
int n;
int k;
int l;
int game[100][100];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
struct info{
	int x;
	char d;
};
info change[100];

struct root{
	int row;
	int col;
};
queue<root> q;

void solve(){
	int cnt=0;
	int r = 0, c = 0;
	int dir = 0;
	int dir_cnt = 0;
	int len = 1;
	game[r][c] = 1;
	q.push({r,c});
	while(1){
		r += dr[dir%4];
		c += dc[dir%4];
		cnt++;
		if(r < 0 || r >= n || c < 0 || c >= n || game[r][c] == 1) break;		if(r < 0 || r >= n || c < 0 || c >= n || game[r][c] == 1) break;
		if(game[r][c] == 2) len++;
		game[r][c] = 1;
		q.push({r, c});
		if(q.size() > len){
			root now = q.front();
			game[now.row][now.col] = 0;
			q.pop();
		}
		if(cnt == change[dir_cnt].x && dir_cnt < l){
			if(change[dir_cnt].d == 'D'){
				dir++;
			}
			if(change[dir_cnt].d == 'L'){
				if(dir==0) dir = 3;
				else dir--;
			}
			dir_cnt++;
		}
	}
	printf("%d", cnt);
}

int main(){
	scanf("%d", &n);
	scanf("%d", &k);
	for(int i=0; i<k; i++){
		int row, col;
		scanf("%d%d", &row, &col);
		game[row-1][col-1] = 2;
	}
	scanf("%d", &l);
	for(int i=0; i<l; i++){
		int x;
		char d;
		scanf("%d %c", &x, &d);
		change[i] = {x, d};
	}
	solve();
	
	return 0;
}
