// boj 1016 Á¦°ö ¤¤¤¤ ¼ö
#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int min, max;
	scanf("%d %d", &min, &max);
	vector <int> list;
	for(int i=2; i*i<=max ;i++) list.push_back(i*i);
	
	int size = list.size();
	
	int cnt=0;
	for(int i=min; i<=max; i++){
		bool flag = true;
		for(int j=0; j<size; j++){
			if(i % list[j] == 0) {
				flag = false;
				break;
			}
		} 
		if(flag) {
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
} 
