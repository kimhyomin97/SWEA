// boj 16916 부분문자열
#include <cstdio>
#include <vector>
using namespace std;

vector <char> str;
vector <char> sub;
int main(){
	char temp;
	
	while(1){
		scanf("%c", &temp);
		if(temp == '\n') break;
		str.push_back(temp);
	}
	while(1){
		scanf("%c", &temp);
		if(temp == '\n') break;
		sub.push_back(temp);
	}
	bool answer = false;
	int str_len = str.size();
	int sub_len = sub.size();
	for(int i=0; i<str_len; i++){
		if(str[i] == sub[0]){
			bool flag = true;
			int len = 0;
			for(int j=i; j<i+sub_len; j++){
				if(str[j] == sub[len++]) continue;
				else{
					flag = false;
					break;
				}
			}
			if(flag && len==sub_len) answer = true;
		}
	}
	if(answer) printf("1");
	else printf("0");
	return 0;
} 
