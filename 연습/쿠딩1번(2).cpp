// Äíµù 1¹ø
#include <cstdio>
#include <vector>
using namespace std;

int main(){
	
	freopen("input.txt", "r", stdin);
	
	int n;
	scanf("%d", &n);
	
	vector <int> ans[100];
	for(int i=0; i<n; i++){
		int mlist[5];
		int len=0;
		for(int m=0; m<5; m++){
			scanf("%d", &mlist[m]);
		}
		char str[100];
		char temp;
		while(scanf("%c", &temp) != EOF){
//			scanf("%c", &temp);
			if(temp == '\n') break;
			str[len++] = temp;
		}
		int mcnt[5] = {0,};
		vector <int> mindex[5];
		for(int j=1; j<len; j++){
			if(str[j] == 'A'){
				mcnt[0]++;
				mindex[0].push_back(j-1);
				str[j] = '?';
			}
			if(str[j] == 'E'){
				mcnt[1]++;
				mindex[1].push_back(j-1);
				str[j] = '?';
			}
			if(str[j] == 'I'){
				mcnt[2]++;
				mindex[2].push_back(j-1);
				str[j] = '?';
			}
			if(str[j] == 'O'){
				mcnt[3]++;
				mindex[3].push_back(j-1);
				str[j] = '?';
			}
			if(str[j] == 'U'){
				mcnt[4]++;
				mindex[4].push_back(j-1);
				str[j] = '?';
			}	
		}
		
		int lenlist[5];
		for(int j=0; j<5; j++) lenlist[j] = mindex[j].size();
		for(int j=0; j<5; j++){
			if(mcnt[j] != 0){
				ans[i].push_back(mlist[j]);
				ans[i].push_back(mcnt[j]);
				for(int k=0;k<lenlist[j];k++){
					ans[i].push_back(mindex[j][k]);
				}
			}
		}
		for(int j=1; j<len; j++){
			ans[i].push_back(str[j]);
		}
	}
	
	for(int i=0; i<n; i++){
		int anslen = ans[i].size(); 
		for(int j=0; j<anslen; j++){
			printf("%d",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
