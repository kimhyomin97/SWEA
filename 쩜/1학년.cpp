// 백준 5557 1학년
// dfs로 짜면 시간초과 발생 
#include <cstdio>
int n;
int arr[100];
int ans = 0;

void dfs(int len, int sum){
	if(len == n-1) {
		if(sum == arr[n-1]) {
			ans++;
		}
		return;
	}
	if(sum < 0) return;
	if(sum > 20) return;
	dfs(len+1, sum + arr[len]);
	dfs(len+1, sum - arr[len]);
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	dfs(0, 0);
	
	printf("%d", ans);
	
	return 0;
} 
