// boj 2003 수들의 합2
#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int list[10000];
	for(int i=0; i<n; i++){
		scanf("%d", &list[i]);
	}
	int offset = 0;
	int len = 0;
	long long sum = 0;
	int cnt = 0;
	while(offset != n){
		if(sum >= m){
			if(sum == m) cnt++;
			sum -= list[offset++];
		}
		else{
			sum += list[len++];
		}
	}
	printf("%d",cnt);
	return 0;
} 
