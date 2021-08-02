// 백준 13458 시험 감독
#include <cstdio>

int n;
int a[1000000];
int b, c;
long long b_cnt = 0, c_cnt = 0;

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}	
	scanf("%d%d", &b, &c);
	
	for(int i=0; i<n; i++){
		int num = a[i];
		num -= b;
		b_cnt++;
		if(num < 0) num = 0;
//		while(num > 0){
//			num -= c;
//			c_cnt++;
//		}
		c_cnt += num / c;
		if(num % c != 0) c_cnt++; 
	}
	
	printf("%lld", b_cnt + c_cnt);
	
	return 0;
} 
