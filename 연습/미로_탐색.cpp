// 2178 ¹Ì·Î Å½»ö
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

vector <vector <int> > arr;
vector <vector <bool> > visit;
int ans = 0;
int n, m;

struct pos{
	int row;
	int col;
};

void bfs(int row, int col){
	queue<pos> q;
	q.push({row, col});
	visit[row][col] = true;
	while(q.size() != 0){
		ans++;
		int len = q.size();
		for(int j=0; j<len; j++){
			pos now = q.front();
			q.pop();
			int nr, nc;
			for(int i=0; i<4; i++){
				nr = now.row + dr[i];
				nc = now.col + dc[i];
				if(nr == n-1 && nc == m-1) return;
				if(nr >= 0 && nr < n && nc >= 0 && nc < m && arr[nr][nc] != 0 && visit[nr][nc] == false){
					visit[nr][nc] = true;
					q.push({nr, nc});
				}
			}
		}
	}
}

int main(){
	scanf("%d %d", &n, &m);
	
	for(int i=0; i<n; i++){
		vector <int> temp;
		vector <bool> temp2;
		for(int j=0; j<m; j++){
			int num;
			scanf("%1d", &num);
			temp.push_back(num);
			temp2.push_back(false);
		}
		arr.push_back(temp);
		visit.push_back(temp2);
	}

	bfs(0, 0);
	printf("%d", ans+1);
	
	return 0;
} 
