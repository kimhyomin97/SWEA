// Äíµù3¹ø
#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int c;
	vector <int> n;
	scanf("%d", &c);
	for(int i=0; i<c; i++){
		int num;
		scanf("%d", &num);
		n.push_back(num);
	}
	for(int i=0; i<c; i++){
		int m=0;
		for(int j=1; j<n[i]; j++){
			if(n[i] % j == 0) m+=j;
		}
		int temp = 0;
		for(int j=1; j<m; j++){
			if(m % j == 0) temp += j;
		}
		if(temp == n[i]) printf("%d\n", m);
		else printf("NO\n");
	}
	
	return 0;
} 
