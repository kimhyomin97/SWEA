// boj 1062 가르침
#include <cstdio>

int n, k;
int bits[51];
int ans = 0;
int ans_cnt = 0;
int list = 0;

void recur(int len, int start){
	if(len == k){
		int cnt = 0;
		for(int i=0; i<n; i++){
			if((ans & bits[i]) == bits[i]) {
			cnt++;
			}
		}
		if(ans_cnt < cnt) ans_cnt = cnt;
		return;
	}
	for(int i=start; i<26; i++){
		// 이부분 start부터 하는게 시간초과 해결법 
//		if(list & (1 << i)){
			if(ans & (1 << i));
			else {
				ans += (1 << i);
				recur(len+1, i);
				ans -= (1 << i);
			}
//		}
	}
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++){
		char temp[16];
		scanf("%s", temp);
		for(int j=0; temp[j]; j++){
			if(list & (1 << temp[j] - 'a'));
			else list += (1 << (temp[j] - 'a'));
			if(bits[i] & (1 << temp[j]-'a'));
			else bits[i] += (1 << (temp[j]-'a'));
		}
	}
	if(k < 5){
		// a n t i c
		printf("0");
		return 0;
	}
	if(k == 26){
		printf("%d",n);
		return 0;
	} 
	k = k-5;
	ans += (1 << ('a' - 'a'));
	ans += (1 << ('n' - 'a'));
	ans += (1 << ('t' - 'a'));
	ans += (1 << ('i' - 'a'));
	ans += (1 << ('c' - 'a'));
	
	recur(0, 0);
	
	printf("%d", ans_cnt);
	
	return 0;
} 
