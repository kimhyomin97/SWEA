// 복잡해보인다 다음에 
#include <stdio.h>

int t;
int n, g;
int arr[501];

int main(){
	scanf("%d",&t);
	for(int i=1; i<t; i++){
		scanf("%d%d", &n, &g);
		for(int j=0; j<n; j++){
			scanf("%d", &arr[j]);
		}
	}	
	
	return 0;
} 
