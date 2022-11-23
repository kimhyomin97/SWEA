// BOJ 10799 ¼è¸·´ë±â
#include <iostream>
#include <vector>
using namespace std;

int main(){
	char str[100001];
	int list[100001];
	cin >> str;
	
	int offset = 0;
	long long sum = 0;
	for(int i=0; str[i]; i++){
		if(str[i]=='(') offset++;
		if(str[i]==')') {
			if(str[i-1]=='('){
				offset--;
				sum += offset;
			}
			else {
				sum += 1;	
				offset--;
			}
		}
	}
	cout << sum;
	return 0;
} 
