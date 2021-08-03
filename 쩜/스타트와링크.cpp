// 백준 14889 스타트와 링크
// 재귀를 활용한 완전탐색 
#include <cstdio>

int n;
int game[20][21];
int select_num[20];
int no_select[20];
int check[20] = {false,};
int ans = 9999999;

void select(int len){
	if(len == n/2) {
		for(int i=0; i<len; i++){
			check[select_num[i]] = true;
		}
		for(int i=0, cnt = 0; i<n; i++){
			if(check[i] == false) no_select[cnt++] = i;
		}
		int sum1 = 0;
		int sum2 = 0;
		for(int i=0; i<len; i++){
			for(int j=i+1; j<len; j++){
				sum1 += game[select_num[i]][select_num[j]] + game[select_num[j]][select_num[i]];
				sum2 += game[no_select[i]][no_select[j]] + game[no_select[j]][no_select[i]];
			}
		}
		int sub = sum1 - sum2;
		if(sub < 0) sub *= -1;
		if(sub < ans) ans = sub;
		for(int i=0; i<n; i++) check[i] = false; 
		return;
	}
	for(int i=0; i<n; i++){
		bool flag = true;
		for(int j=0; j<n/2; j++){
			if(select_num[j] == i) flag = false;
		}
		if(flag){
			select_num[len] = i;
			select(len+1);
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &game[i][j]);
		}
		select_num[i] = -1;
	}
	
	printf("\n");
	select(0);
	
	printf("%d", ans);
	
	return 0;
} 


//1 3 6		2 4 5
//
//1,3 1,6 3,6
//2+1 5+1 5+3 = 3 + 6 + 8 = 17
//
//2,4 2,5 4,5
//3+2 4+2 4+4 = 5 + 6 + 8 = 19


