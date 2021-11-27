// boj 18119 단어 암기
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main(){
	int n, m;
	vector <int> bits;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		char temp[1000];
		scanf("%s", temp);
		int num=0;
		for(int j=0; temp[j]; j++){
			num |= (1 <<temp[j]-'a');
		}
		bits.push_back(num);
	}
	int remember = 0;
	for(int i=0; i<26; i++) remember |= (1 << i);
	for(int i=0; i<m; i++){
		int a;
		char temp;
		scanf("%d %c", &a, &temp);
		if(a == 1){
			if(remember | (1 << temp - 'a')){
				printf("before : %d\n", remember);;
				remember &= ~(1 << temp - 'a');
				printf("after : %d\n", remember);
			}
		}
		else{
			remember |= (1 << temp - 'a');
		}
		int ans = 0;
		for(int j=0; j<n; j++){
			bool flag = true;
			for(int k=0; k<26; k++){
				if(bits[j] & (i << k)){
					if(remember & (i << k));
					else{
						flag = false;
						break;
					}
				}
			}
			if(flag) ans++;
		}
		printf("%d\n", ans);
	}
	
	
	return 0;
} 
