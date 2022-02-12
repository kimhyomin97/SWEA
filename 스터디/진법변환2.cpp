// boj 11005 진법 변환 2
#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int n, b;
	scanf("%d %d", &n, &b);
	
	vector <int> list;
	while(n > 0){
		list.push_back(n%b);
		n /= b;
	} 
	int size = list.size();
	for(int i=size-1; i>=0; i--){
		if(list[i] >= 10) printf("%c", 'A'+list[i]-10);
		else printf("%d", list[i]);
	}
	
	return 0;
} 
