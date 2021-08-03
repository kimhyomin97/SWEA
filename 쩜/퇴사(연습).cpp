// 백준 14501 퇴사 (연습)
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
		scanf("%d %d", &t[i], &p[i]);
	}
	
	for(int i=n-1; i>=0; i--){
		if(t[i] + i > n) dp[i] = dp[i+1];
		else{
			dp[i] = max(dp[i+t[i]]+p[i], dp[i+1]);
		}
	}
	printf("%d", dp[0]);
	
	return 0;
}
