#include <cstdio>
//#include <vector>
//using namespace std;
int n;
int map[100][100];
//vector <vector <int>> map;
unsigned int answer = 0;

void dfs(int row, int col){
	if(row == n-1 && col == n-1){
		answer++;
		return;
	}
	int offset = map[row][col];
	if(offset == 0) return;
	if(row+offset < n) {
		dfs(row+offset, col);
	}
	if(col+offset < n){
		dfs(row, col+offset);
	}
	return;
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &map[i][j]);
//			int num;
//			scanf("%d", &num);
//			map[i].push_back(num);
		}
	}
	dfs(0, 0);
	printf("%u", answer);
	
	return 0;
}
