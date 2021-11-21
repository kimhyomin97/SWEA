// boj 20437 문자열 게임2
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	
	for(int i=0; i<T; i++){
		string str;
		int k;
		char temp[10001];
		vector <int> cnt[26];
		scanf("%s", &temp);
		str = temp;
		scanf("%d", &k);
		int min_ans=10001, max_ans=-1;
		for(int j=0; str[j]; j++){
			cnt[str[j]-97].push_back(j);
		}
		for(int j=0; j<26; j++){
			int min=10001, min2=10001, max=-1;
			if(cnt[j].size() >= k){
				for(int s=0; s+k-1<cnt[j].size(); s++){
					if(cnt[j][s+k-1] - cnt[j][s] < min) {
						min = cnt[j][s+k-1] - cnt[j][s];
					}
					if(cnt[j][s+k-1] - cnt[j][s] > max) {
						max = cnt[j][s+k-1] - cnt[j][s];	
					}
				}
				if(min < min_ans) min_ans = min;
				if(max > max_ans) max_ans = max;
			}
		}
		if(max_ans == -1) printf("-1\n");
		else
			printf("%d %d\n", min_ans+1, max_ans+1);
	}
	
	return 0;
} 
