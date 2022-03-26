#include <iostream>
#include <queue>
using namespace std;
struct info{
	int row;
	int col;
};
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int testcase;
	scanf("%d", &testcase);
	for(int t=0; t<testcase; t++){
		int row, col;
		scanf("%d %d", &row, &col);
		char map[103][103];
		queue<info> target;
		for(int i=0; i<=row+1; i++){
			map[i][0] = '.';
			map[i][col+1] = '.';
		}
		for(int i=0; i<=col+1; i++){
			map[0][i] = '.';
			map[row+1][i] = '.';
		}
		for(int i=1; i<=row; i++){
			for(int j=1; j<=col; j++){
				cin >> map[i][j];
				if(map[i][j] == '$') target.push({i, j});
			}
		}
		int dr[4] = {1, -1, 0, 0};
		int dc[4] = {0, 0, 1, -1};
		int cnt1[103][103], cnt2[103][103], cnt3[103][103];
		for(int i=0; i<=row+1; i++){
			for(int j=0; j<=col+1; j++){
				cnt1[i][j] = -1;
				cnt2[i][j] = -1;
				cnt3[i][j] = -1;
			}
		}
		queue<info> q;
		q.push({0, 0});
		cnt1[0][0] = 0;
		int len = 0;
		while(q.size() != 0){
			info now = q.front();
			q.pop();
			for(int i=0; i<4; i++){
				int nr = now.row + dr[i];
				int nc = now.col + dc[i];
				if(nr>=0&&nr<row+2&&nc>=0&&nc<col+2&&map[nr][nc]!='*'){
					if(map[nr][nc]=='#') len++;
					if(cnt1[nr][nc] == -1 || cnt1[nr][nc] > len){
						cnt1[nr][nc] = len;
					}
				}
			}
		}
		
	}
	
	return 0;
}
