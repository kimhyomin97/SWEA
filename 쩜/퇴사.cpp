// 백준 14501 퇴사 // 다시 
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int t[16];
int p[16];
int dp[16];

int ans = 0;

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &t[i]);
		scanf("%d", &p[i]);
	}
	
	for(int i=n-1; i>=0; i--){
		// 뒤부터 계산하는 방법
		if(t[i] + i > n) dp[i] = dp[i+1];
		else{
			dp[i] = max(dp[i+t[i]]+p[i], dp[i+1]);
		}
	}
//	for(int i=0; i<n; i++){
//		printf("%d\n", dp[i]);
//	}
	printf("%d", dp[0]);
	
	return 0;
} 
