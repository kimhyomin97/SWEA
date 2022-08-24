// BOJ 12865 Æò¹üÇÑ ¹è³¶ DP
#include <iostream>
#include <algorithm>
using namespace std;

struct info{
	int weight;
	int value;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	
	info list[n];
	for(int i=0; i<n; i++){
		cin >> list[i].weight >> list[i].value;
	}
	
	int dp[n][k+1];
	for(int i=0; i<n; i++){
		for(int j=1; j<=k+1; j++){
//			if(i==0){
//				if(list[i].weight <= j) dp[i][j] = list[i].value;
//				else dp[i][j] = 0;
//			} 
//			else {
//				if(j-list[i].weight > 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-list[i].weight] + list[i].value);
//				else dp[i][j] = dp[i-1][j];
//			}
			
		}
	}
	
	cout << dp[n-1][k+1];
	
	return 0;
} 
