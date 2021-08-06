// 백준 14890 경사로
#include <cstdio>

int n, l;
int map[100][100];

int ans = 0;

void solve_r(int col){
//	for(int i=0; i<n; i++){
//		map[row][i];
//	}
	int start = 0;
	int end = 1;
	int seq = 1;
	bool pass = true;
	
	while(1){
		if(end > n-1) break;
		int offset = map[start][col] - map[end][col];
		if(offset == 0){
			end++;
			seq++;
		}
		else if(offset == -1){
			// 위방향 경사로
			if(seq < l){
				pass = false;
				break;
			} 
			else{
				start = end;
				end++;
				seq = 1;
			}
		}
		else if(offset == 1){
			// 아래방향 경사로
			seq = 0;
			bool flag = false;
			int index;
			for(int i=end; i<n; i++){
				offset = map[start][col] - map[i][col];
				index = i;
				if(offset == 1) seq++;
				else{
					break;
				}
				if(seq == l) {
					flag = true;
					break;
				}
			}
			if(flag == false){
				pass = false;
				break;
			}
			else{
				start = index;
				end = index+1;
				seq = 0;
			}
		}
		else if(offset > 1 || offset < -1){
			pass = false;
			break;
		}
	}
//	printf(" col : %d \n", pass);
	if(pass == true) ans++;
}

void solve_c(int row){
//	for(int i=0; i<n; i++){
//		map[i][col];
//	}
	int start = 0;
	int end = 1;
	int seq = 1;
	bool pass = true;
	
	while(1){
		if(end > n-1) break;
		int offset = map[row][start] - map[row][end];
		if(offset == 0){
			end++;
			seq++;
		}
		else if(offset == -1){
			// 위방향 경사로
			if(seq < l){
				pass = false;
				break;
			} 
			else{
				start = end;
				end++;
				seq = 1;
			}
		}
		else if(offset == 1){
			// 아래방향 경사로
			seq = 0;
			bool flag = false;
			int index;
			for(int i=end; i<n; i++){
				offset = map[row][start] - map[row][i];
				index = i;
				if(offset == 1) seq++;
				else{
					break;
				}
				if(seq == l) {
					flag = true;
					break;
				}
			}
//			printf(" index : %d %d ", index, flag);
			if(flag == false){
				pass = false;
				break;
			}
			else{
				start = index;
				end = index+1;
				seq = 0;
			}
		}
		else if(offset > 1 || offset < -1){
			pass = false;
			break;
		}
	}
//	printf("row : %d \n", pass);
	if(pass == true) ans++;
}

int main(){
	scanf("%d%d", &n, &l);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &map[i][j]);
		}
	}
	
	for(int i=0; i<n; i++){
		solve_r(i);
	}
	for(int i=0; i<n; i++){
		solve_c(i);
	}
	
	
	printf("%d", ans);
	return 0;
} 
