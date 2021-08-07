// 백준 1256 사전
#include <cstdio>

int n, m;
long long k;
long long fact(int n, int m){
	long long res = 1;
	int max = n;
	int min = n;
	if(max < m) max = m;
	if(min > m) min = m;
	for(int i=n+m; i>max; i--){
		res *= i;
	}
	for(int i=min; i>0; i--){
		res /= i;
	}
	return res;
}

int main(){
	scanf("%d%d%lld", &n, &m, &k);
	
	printf("%lld", fact(n, m));
	return 0;
} 

//aa zz => 6개 == 4! / 2! 2! 
//aazz
//azaz
//azza
//zaaz
//zaza
//zzaa
