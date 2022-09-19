//BOJ 2206 벽 부수고 이동하기 
#include <iostream>
using namespace std;

int ans = 1000001;
int n, m;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
char map[1001][1001];
bool visit[1001][1001] = {false};

void recur(int row, int col, int sum, int break_cnt){
	if(row == n-1 && col == m-1){
		if(ans > sum) ans = sum;
		return;
	}
	for(int i=0; i<4; i++){
		int nr = row + dr[i];
		int nc = col + dc[i];
		if(nr >= 0 && nr < n && nc >= 0 && nc < m && visit[nr][nc] == false){
			if(map[nr][nc]=='0'){
				visit[nr][nc] = true;
				recur(nr, nc, sum+1, break_cnt);
				visit[nr][nc] = false;
			}
			if(break_cnt == 0){
				visit[nr][nc] = true;
				recur(nr, nc, sum+1, 1);
				visit[nr][nc] = false;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		cin >> map[i];
	}
	
	recur(0, 0, 1, 0);
	
	if(ans == 1000001) cout << -1;
	else cout << ans;
	
	return 0;
} 
