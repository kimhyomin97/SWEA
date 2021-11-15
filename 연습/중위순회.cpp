#include <cstdio>

int arr[8] = {0,1,2,3,4,5,6,7};
bool visit[8] = {false,};
int n = 8;

void dfs(int num){
	if(num == 0) return;
	visit[num] = true;
	printf("%d ", arr[num]);
	if(visit[num*2] == false) dfs(num*2);
	if(visit[num*2+1] == false) dfs(num*2+1);
	if(visit[num/2] == false) dfs(num/2);
}

int main(){
	for(int i=0; i<n; i++) printf("%d ", arr[i]);
	printf("\n");
	printf("출력결과 : ");
	dfs(1);
	
	return 0;
}
