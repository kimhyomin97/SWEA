// SWEA 5603 건초더미
#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int testcase;
	cin >> testcase;
	
	for(int T=1; T<=testcase; T++){
		int n;
		cin >> n;
		int list[n];
		int sum = 0;
		for(int i=0; i<n; i++) {
			cin >> list[i];
			sum += list[i];
		}
		int avg = sum / n;
		
		int ans = 0;
		for(int i=0; i<n; i++){
			if(list[i] >= avg){
				ans += list[i] - avg;
			}
			else ans += avg - list[i];
		}
		
		ans /= 2;
				
		cout << "#" << T << " " << ans << "\n";
	}
	
	return 0;
} 
