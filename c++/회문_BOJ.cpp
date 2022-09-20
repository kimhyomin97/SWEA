// BOJ 17609 È¸¹®
#include <iostream>
//#include <string.h>
#include <string>
using namespace std;

string temp;

int check(int left, int right, int cnt){
	while(left < right){
		if(temp[left] != temp[right]){
			if(cnt == 0){
				if(check(left+1, right, 1) == 0 || check(left, right-1, 1) == 0) return 1;
			}
			return 2;
		}
		left++;
		right--;
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
//		char temp[31];
		cin >> temp;
//		int left = 0, right = strlen(temp)-1;
		cout << check(0, temp.length()-1, 0) << "\n";
		
//		int cnt = 0;
//		while(left < right){
//			if(temp[left] != temp[right]) {
//				if(cnt == 1){
//					cnt = 2;
//					break;
//				}
//				if(temp[left+1]==temp[right]) {
//					cnt++;
//					left++;
//					continue;
//				}
//				else if(temp[left]==temp[right-1]) {
//					cnt++;
//					right--;
//					continue;
//				}
//				else {
//					cnt = 2;
//					break;
//				}
//			}
//			left++;
//			right--;
//		}
//		if(cnt == 0) cout << 0;
//		else if(cnt == 1) cout << 1;
//		else cout << 2;
//		cout << "\n";
	}
	
	
	return 0;
}
