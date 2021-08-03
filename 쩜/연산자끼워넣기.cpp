// 백준 14888 연산자 끼워넣기
#include <csdtio>

int n;
int arr[11];
int oper[4];

int oper_list[11];

int max = -99999999;
int min = 99999999;

void recur(int len){
	if(len == n-1) return;
	for(int i=0; i<n-1; i++){
		
	}
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	for(int i=0; i<4; i++){
		scanf("%d", &oper[i]);
	}
	
	recur(0);
	
	return 0;
}
