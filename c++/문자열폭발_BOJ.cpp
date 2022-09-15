// BOJ 9935 문자열 폭발
// 시간초과 
#include <iostream>
#include <string>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str; // 1 <= str.size() <= 100000
	string bomb; // 1 <= bomb.size() << 36
	
	cin >> str;
	cin >> bomb;

	int b_size = bomb.size();
	for(int i=0; i<str.size()-b_size+1; i++){
		if(str.size() == 0){
			str = "FRULA";
			break;
		}
		if(bomb.compare(str.substr(i, b_size)) == 0){
			str.replace(i, b_size, "");
			i = -1;
		}
	}
	
	cout << str;
	
	return 0;
} 
