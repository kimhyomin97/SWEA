// boj 1969 DNA
#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int cnt[51][26] = {0,};
	for(int i=0; i<n; i++){
		char line[1001];
		scanf("%s", line);
		for(int j=0; line[j]; j++){
			cnt[j][line[j]-'A']++;
		}
	}
	int answer[51];
	int sum = 0;
	for(int i=0; i<m; i++){
		char temp;
		int index = 0;
		for(int j=0; j<26; j++){
			if(cnt[i][j] > index){
				temp = j+'A';
				index = cnt[i][j];
			}
		}
		answer[i] = temp;
		sum += n - cnt[i][answer[i]-'A'];
	}
	for(int i=0; i<m; i++) printf("%c", answer[i]);
	printf("\n%d", sum);
	return 0;
}
