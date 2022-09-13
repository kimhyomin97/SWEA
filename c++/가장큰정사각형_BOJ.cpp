// BOJ 1915 가장 큰 정사각형
#include <iostream>
#include <string>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	int map[n][m];
	int dp[n][m] = {0};
	
	for(int i=0; i<n; i++){
		string temp;
		cin >> temp;
		for(int j=0; j<m; j++){
			map[i][j] = temp[j]-48;
		}			
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(map[i][j] == 0) dp[i][j] = 0;
			else{
				
			}
		}
	}
	
	return 0;
} 
