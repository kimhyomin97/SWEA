// boj 18119 단어 암기
#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int bits[n] = {0,};
	for(int i=0; i<n; i++){
		char temp[1001];
		scanf("%s", temp);
		for(int j=0; temp[j]; j++){
			if(bits[i] & (1 << (temp[j]-'a')));
			else bits[i] += 1 << (temp[j]-'a');
			
		}
	}
	
	int rem = 0;
	for(int i=0; i<26; i++) rem += (1 << i);
	for(int i=0; i<m; i++){
		int num;
		char alpha;
		scanf("%d %c", &num, &alpha);
		if(num == 1){
			rem -= 1 << (alpha-'a');
		}
		else{
			if(rem & (1 << (alpha-'a')));
			else rem += 1 << (alpha-'a');
		}
		int cnt = 0;
		for(int j=0; j<n; j++){
			if((bits[j] & rem) == bits[j]) cnt++;
		}
		printf("%d\n", cnt);
	}
	
	return 0;
} 
