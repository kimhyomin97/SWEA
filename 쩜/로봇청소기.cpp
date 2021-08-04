// 백준 14503 로봇 청소기
#include <cstdio>

int n, m;
int map[50][50];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};

//int dr1[4] = {-1, 0, 1, 0};
//int dc1[4] = {0, -1, 0, 1};
//
//int dr2[4] = {0, -1, 0, 1};
//int dc2[4] = {1, 0, -1, 0};
//
//int dr3[4] = {1, 0, -1, 0};
//int dc3[4] = {0, 1, 0, -1};

int ans = 0;

//  0
//3   1
//  2

int main(){
	scanf("%d%d", &n, &m);
	int r, c, d;
	scanf("%d%d%d", &r, &c, &d);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &map[i][j]);
		}
	}
	while(1){
		if(map[r][c] == 0){
			ans++;
			map[r][c] = 2;
		}
		bool flag = false;
		for(int i=0; i<4; i++){
			int index = i + 4 - d;
			if(index < 0) index *= -1;
			index = index % 4;
			int nr = r + dr[index];
			int nc = c + dc[index];
			if(map[nr][nc] == 0){
//				printf("sum : %d %d %d %d\n", r, c, d, i);
				d = (3 - index)%4;
				r = nr;
				c = nc;
				flag = true;
				break;
			}
		}
		if(flag == false){
			if(d == 0) r++;
			if(d == 1) c--;
			if(d == 2) r--;
			if(d == 3) c++;
			if(r<0 || r>=n || c<0 || c>=m || map[r][c] == 1)break;
		}
//		if(ans == 5) break;
	}
	
//	for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			printf("%d ", map[i][j]);
//		}
//		printf("\n");
//	}
	printf("%d", ans);
	return 0;
}
