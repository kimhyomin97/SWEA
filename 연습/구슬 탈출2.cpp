// 백준 구슬 탈출 2 (13460)
#include <cstdio>

int n, m;
char game[10][11];

bool check(int row, int col){
	if(row >= m || row < 0 || col >= n || col < 0) return false;
	if(game[row][col] == '.' || game[row][col] == '#') return false;
}

void move_r(int row, int col, int dr){
	while(row > 0 && row < m){
		s
	}
}
void move_r(int row, int col, int dr){
	
}


void recur(){
	
	
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++){
		scanf("%s", game[i]);
	}
	
	recur();
	
	return 0;
} 
