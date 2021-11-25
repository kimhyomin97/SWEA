// boj 13235 ÆÓ¸°µå·Ò
#include <cstdio>
int main(){
	char str[21];
	scanf("%s", str);
	int len=0;
	for(int i=0; str[i]; i++){
		len++;
	}
	for(int i=0; i<len; i++){
		if(str[i] != str[len-i-1]){
			printf("false");
			return 0;
		}
	}
	printf("true");
	return 0;
} 
