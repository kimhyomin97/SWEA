// swea 최대 상금
#include <cstdio>

int test;
int num;
int cnt;
int arr[6];
int len = 0;
int ans = 0;

void trans(){
	num = 0;
	for(int i = len-1; i>=0; i++){
		
	}
}

void solve(){
	
	
}

int main(){
	scanf("%d", &test);	
	for(int t=1; t<=test; t++){
		scanf("%d", &num);
		scanf("%d", &cnt);
		while(num > 0){
			arr[len++] = num%10;
			num /= 10;
		}
		for(int i=0; i<len; i++) printf("%d ", arr[i]);
//		solve();
		
		printf("#%d %d\n", t, ans);
		len = 0;
	}
	
	return 0;
} 
