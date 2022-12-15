// 백준 정수 삼각형 문제
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int tree[500][501] = {0,};
int dp[500][501];
long long res = 0;
int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			scanf("%d", &tree[i][j]);
		}
	}
//	res += tree[0][0];
	dp[0][0] = tree[0][0];
	for(int i=1; i<n; i++){
		for(int j=0; j<=i; j++){
			if(j == 0) dp[i][j] = dp[i-1][0] + tree[i][j];
			else if(j == i) dp[i][j] = dp[i-1][i-1] + tree[i][j];
			else{
				dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tree[i][j];
			}
		}
	}
	for(int i=0; i<n; i++){
		if(res < dp[n-1][i]) res = dp[n-1][i];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	printf("%d", res);
//	int pos = 0;
//	for(int i=1; i<n; i++){
//		int num1 = tree[i][pos] + tree[i+1][pos];
//		int num2 = tree[i][pos+1] + tree[i+1][pos+2];
//		if(tree[i+1][pos+1] > tree[i+1][pos] && tree[i+1][pos+1] > tree[i+1][pos+2]){
//			if(tree[i][pos] > tree[i][pos+1]){
//				res += tree[i][pos];
//			}
//			else{
//				res += tree[i][pos+1];
//				pos++;
//			}
//		}
//		else if(num1 > num2){
//			res += tree[i][pos];
//		}
//		else{
//			res += tree[i][pos+1];
//			pos++;
//		}
//	}
//	printf("%d", res);
	
	return 0;
} 
//7 + 3 + 8 + 7 + 5
