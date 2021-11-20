// boj 10809 ¾ËÆÄºª Ã£±â
#include <cstdio>

int main(){
	char arr[100];
	int alpha[26];
	for(int i=0; i<26; i++) alpha[i] = -1;
	scanf("%s", arr);
	for(int i=0; arr[i]; i++){
		if(alpha[arr[i]-97] == -1){
			alpha[arr[i]-97] = i;
		}
	}
	for(int i=0; i<26; i++) printf("%d ", alpha[i]);
	return 0;
} 
