// 백준 스타트와 링크 연습
#include <cstdio>

int n;
int game[20][21];
int select[10];

int sum1 = 0, sum2 = 0;

void combi(int len, int num){
	if(len == n/2) {
		for(int i=0; i<len; i++) printf("%d ", select[i]);
		printf("\n");	
		return;
	}
	
	for(int i=num; i<n; i++){
		if(i < len) continue;
		select[len] = i;
		combi(len+1, num+1);
	}
}

// 1 2 3 4
// 1 2
// 1 3
// 1 4
// 2 3
// 2 4
// 3 4


int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &game[i][j]);
		}
		select[i/2] = -1;
	}
	
	combi(0, 0);
	
	
	return 0;
} 


//1 3 6		2 4 5
//
//1,3 1,6 3,6
//2+1 5+1 5+3 = 3 + 6 + 8 = 17
//
//2,4 2,5 4,5
//3+2 4+2 4+4 = 5 + 6 + 8 = 19


