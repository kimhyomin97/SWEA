// 백준 스타트와 링크 연습
#include <cstdio>

int n;
int game[20][21];
int select[10];
bool visit[20] = {false,};

int sum1 = 0, sum2 = 0;
int ans = 99999999;

void combi(int len, int num){
	if(len == n/2) {
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(visit[i] == true && visit[j] == true){
					sum1 += game[i][j] + game[j][i];
				}
				if(visit[i] == false && visit[j] == false){
					sum2 += game[i][j] + game[j][i];
				}
			}
		}
		int temp = sum1 - sum2;
		if(temp < 0) temp *= -1;
		if(temp < ans) ans = temp;
		sum1 = 0; sum2 = 0;
		return;
	}
	
	for(int i=num; i<n; i++){
		visit[i] = true;
		combi(len+1, i+1);
		visit[i] = false;
	}
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &game[i][j]);
		}
		select[i/2] = -1;
	}
	
	combi(0, 0);
	printf("%d", ans);
	
	return 0;
}

