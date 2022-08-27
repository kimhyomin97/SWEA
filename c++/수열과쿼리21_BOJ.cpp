// BOJ 16975 수열과 쿼리 21
#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	int list[n];
	for(int i=0; i<n; i++){
		cin >> list[i];
	}
	
	int m;
	cin >> m;
	for(int i=0; i<m; i++){
		int a;
		cin >> a;
		if(a == 1){
			int left, right, num;
			cin >> left >> right >> num;
			
		}
		if(a == 2){
			int index;
			cin >> index;
			
		}
	}
	
	return 0;
} 
