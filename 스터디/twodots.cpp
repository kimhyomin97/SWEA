// boj 16929 Two Dots
#include <cstdio>
#include <iostream>
using namespace std;

int n, m;
int map[50][50];

int main(){
	scanf("%d %d", &n, &m);
	
	for(int i=0; i<n; i++){
//		scanf("%s", &map[i]);
//		cin  map[i][j];
		cin >> map[i][j];
		for(int j=0; j<m; j++){
//			scanf("%c", &map[i][j]);
			cin >> map[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}
