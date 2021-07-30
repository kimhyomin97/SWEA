// 백준 구간 합 구하기 문제
#include <stdio.h>
#define max (1 << 20)

//#define max 1000000
int n, m, k;
//int max = 1000000;
long long tree[max*2];

void update(int num){
	if(num == 0) return;
	else{
		int temp = num/2;
		tree[temp] = tree[temp*2] + tree[temp*2 + 1];
		update(temp);
	}
//	while(num != 0){
//		num /= 2;
//		tree[num] = tree[num*2] + tree[num*2+1];
//	}
}

void index_sum(int s, int e){
	long long res = 0;
	while(s <= e){
		if(s%2 == 1) res += tree[s++];
//		printf("res : %d\n", res);
		if(e%2 == 0) res += tree[e--];
		s/=2;
		e/=2;
//		printf("res : %d\n", res);
	}
	printf("%lld\n", res);
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0; i<n; i++){
		int num;
		scanf("%d", &num);
		tree[max + i] = num;
	}
	for(int i=1; i<=n; i+=2){
		update(i + max);
	}
	for(int i=1; i<=m+k; i++){
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if(a == 1){
			tree[max + b-1] = c;
			update(max + b-1);
		}
		if(a == 2){
			index_sum(max + b - 1, max + c - 1);
		}
	}
//	printf("\n");
//	for(int i=0; i<=n; i++){
//		printf("%d : %d\n", i, tree[max +i]);
//	}
//	printf("\n");
//	for(int i=0; i<=32; i++){
//		printf("%d : %d\n", i, tree[i]);
//	}
	
	
} 
