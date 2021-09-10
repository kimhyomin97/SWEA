// 백준 17144 미세먼지 안녕!
#include <cstdio>

int r, c, t;
int map[50][50];
int ans = 0;

int main(){
	scanf("%d%d%d", &r, &c, &t);
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			scanf("%d", map[i][j]);
		}
	}
	
	
	
	return 0;
} 
