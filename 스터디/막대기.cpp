// boj 1094 ¸·´ë±â
#include <cstdio>

int main(){
	int num;
	scanf("%d", &num);
	// 32 32 -> 32
	// 16 16 -> 16 16
	// 16 8 8 -> 16 8 -> 24 return
	
	int cnt = 0;
	for(int i=6; i>=0; i--){
		if(num & (1 << i)){
			cnt++;
		}
	}
	
	printf("%d", cnt);
	
	return 0;
}
