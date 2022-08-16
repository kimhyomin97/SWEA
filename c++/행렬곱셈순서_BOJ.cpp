// BOJ 11049 Çà·Ä °ö¼À ¼ø¼­
#include <iostream>
using namespace std;

struct info{
	int row;
	int col;
};

int main(){
	ios::sync_with_stdio(NULL);
	cin.tie(false);
	cout.tie(false);
	
	int n;
	cin >> n;
	
	info list[n];
	for(int i=0; i<n; i++){
		int r, c;
		cin >> r >> c;
		list[i] = {r, c};
	}
	
	int dp[n][n];
	for(int i=0; i<n; i++){
		dp[j][i+1];
		for(int j=0; j<n; j++){
			
		}
	}
	
	return 0;
} 
