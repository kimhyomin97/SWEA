// boj 10974 모든 순열
#include <cstdio>

int n;
bool check[9] = {false, };
int arr[8] = {0, };

void recur(int len){
	if(len == n){
		for(int i=0; i<n; i++){
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for(int i=1; i<=n; i++){
		if(check[i] == false){
			check[i] = true;
			arr[len] = i;
			recur(len+1);
			check[i] = false;
		}
	}
}

int main(){
	scanf("%d", &n);
	
	recur(0);
	
	return 0;
} 
