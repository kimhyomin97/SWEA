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
	int str_len = str.size();
	int sub_len = sub.size();
	
	int str_sum = 0;
	int sub_sum = 0;
	
	for(int i=0; i<sub_len; i++) {
		sub_sum += sub[i];
		str_sum += str[i];
	}
	
	int offset1 = 0, offset2 = sub_len;
	
	for(int i=0; i<=str_len-sub_len; i++){
		if(str_sum == sub_sum){
			bool flag = true;
			for(int j=i; j<i+sub_len; j++){
				if(str[j] != sub[j-i]){
					flag = false;
					break;
				}
			}
			if(flag) {
				printf("1");
				return 0;
			}
		}
		str_sum -= str[offset1++];
		str_sum += str[offset2++];
	}
	printf("0");
	return 0;
}
