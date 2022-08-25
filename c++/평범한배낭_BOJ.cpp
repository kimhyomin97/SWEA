// BOJ 12865 평범한 배낭 DP
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
	
	int dp[k+1] = {0};
	
	for(int i=0; i<n; i++){
		for(int j=k; j>0; j--){ 
		// 이부분 0부터 시작하면 값이 중복되는 오류 발생 -> 뒤에서부터 오는 방법으로 해결 
			if(j - list[i].weight < 0) continue;
			dp[j] = max(dp[j], dp[j-list[i].weight] + list[i].value);
		}
	}
	
	cout << dp[k];
	
	return 0;
} 
