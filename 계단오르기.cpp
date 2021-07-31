// 백준 계단 오르기 문제
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int tree[301];
int dp[301][2] = {0,};

int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &tree[i]);
	}
	dp[1][0] = tree[1]; // 1칸 올라온 경우 
	dp[1][1] = tree[1]; // 2칸 올라온 경우 
	for(int i=2; i<=n; i++){
		dp[i][1] = max(dp[i-2][0], dp[i-2][1]) + tree[i];
		dp[i][0] = dp[i-1][1] + tree[i];
	}	
	printf("%d", max(dp[n][0], dp[n][1]));
	
	return 0;
} 
