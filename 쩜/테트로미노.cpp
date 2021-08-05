// 백준 14500 테트로미노
// 그리디방법은 테트로미노 벡터 생성할 때 노가다가 필요하다 
#include <cstdio>
#include <vector>
using namespace std;

int n, m;
int map[500][500];

struct info {
	int row;
	int col;
};

vector<info> tetro[5];
int ans = 0;

int cal(int r, int c){
	int max = 0;
	for(int i=0; i<5; i++){
		int sum = 0;
		for(int j=0; j<4; j++){
			info now = tetro[i][j];
			if(now.row+r < 0 || now.row+r >= n || now.col+c < 0 || now.col+c >= m) return -1;
			sum+=map[now.row+r][now.col+c];
		}
		if(sum > max) max = sum;
	}
	return max;
}
void solve(){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int sum = cal(i,j);
			if(ans < sum) ans = sum;
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d",&map[i][j]);
		}
	}
	
	tetro[0].push_back({0,0});
	tetro[0].push_back({0,1});
	tetro[0].push_back({0,2});
	tetro[0].push_back({0,3});
	
	tetro[1].push_back({0,0});
	tetro[1].push_back({0,1});
	tetro[1].push_back({1,0});
	tetro[1].push_back({1,1});
	
	tetro[2].push_back({0,0});
	tetro[2].push_back({1,0});
	tetro[2].push_back({2,0});
	tetro[2].push_back({2,1});
	
	tetro[3].push_back({0,0});
	tetro[3].push_back({1,0});
	tetro[3].push_back({1,1});
	tetro[3].push_back({2,1});
	
	tetro[4].push_back({0,0});
	tetro[4].push_back({0,1});
	tetro[4].push_back({0,2});
	tetro[4].push_back({1,1});

	solve();
	printf("%d", ans);
	return 0;
} 
