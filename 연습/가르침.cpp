// boj 1062 °¡¸£Ä§
#include <cstdio>
#include <vector>
using namespace std;

int n, k;
vector <int> bits;
int compare = 532741;
// a n t i c
int ans = 0;
void dfs(int num, int len){
	if(len == k-5){
		int cnt = 0;
		for(int i=0; i<n; i++){
			bool flag = true;
			for(int j=0; j<26; j++){
				if(bits[i] & (1 << j)){
					if(num & (1 << j));
					else{
						flag = false;
						break;
					}
				}
			}
			if(flag) cnt++;
		}
		if(ans < cnt) {
			ans = cnt;
//			for(int i=0; i<26; i++){
//				if(num & (1 << i)) printf("%c ", 'a'+i);
//			}
//			printf("\n");
		}
		return;
	}
	for(int i=0; i<26; i++){
		if(num & (1 << i));
		else{
			num |= (1 << i);
			dfs(num, len+1);
			num ^= (1 << i);
		}
	}
}

int main(){
	scanf("%d %d", &n, &k);
	char temp[16];
	for(int i=0; i<n; i++){
		scanf("%s", temp);
		int num = 0;
		for(int j=0; temp[j]; j++){
			num |= (1 << (temp[j]-'a'));
//			if(num & (1<<(temp[j]-'a')));
//			else{
//				num |= (1 << (temp[j]-'a'));
//			}
		}
		bits.push_back(num);
	}
	
	if(k < 5) {
		printf("0");
		return 0;
	}
	
	dfs(532741, 0);
	printf("%d", ans);
	return 0;
} 
