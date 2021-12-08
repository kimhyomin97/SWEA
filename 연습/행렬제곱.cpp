// boj 10830 Çà·Ä Á¦°ö
#include <cstdio>

int main(){
	int n, b;
	scanf("%d %d", &n, &b);
	
	int arr[n][n];
	int ans[n][n];
	int temp[n][n];
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int num;
			scanf("%d", &num);
			arr[i][j] = num;
			ans[i][j] = num;
		}
	}
	for(int mul=0; mul<=b-2; mul++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				int num = 0;
				for(int k=0; k<n; k++){
					num += (ans[i][k] * arr[k][j])%1000;
				}
				temp[i][j] = num%1000;
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				ans[i][j] = temp[i][j];
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d ", ans[i][j]%1000);
		}
		printf("\n");
	}
	return 0;
} 
