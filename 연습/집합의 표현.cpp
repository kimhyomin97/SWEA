// 이 문제는 swea가 아닌 백준에 있는 문제 
#include <cstdio>

int n, m;
int set[1000001];
 
int find(int num){
	if(set[num] == num) return num;
	else{
		return set[num] = find(set[num]);
	}
} 

void uni(int b, int c){
	int num1 = find(b);
	int num2 = find(c);
	if(num1 == num2) return;
	else{
		set[num2] = num1;
	}
}
 

int main(){
	scanf("%d%d",&n, &m);
	for(int i=0; i<=n; i++){
		set[i] = i;
	}	
	for(int i=0; i<m; i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if(a == 0){
			uni(b, c);
		}
		if(a == 1){
			int num1 = find(b);
			int num2 = find(c);
			if(num1 == num2) printf("YES\n");
			else printf("NO\n");
		}
	}
	
	return 0;
}
