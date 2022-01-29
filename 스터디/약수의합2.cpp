// boj 17427
#include <cstdio>

int main(){
	int num;
	scanf("%d", &num);
	
	// 4 -> 1 2 4
	// 1			1		1
	// 1 2			3		2
	// 1 3			4		3
	// 1 2 4		7		4
	// 1 5			6		5
	// 1 2 3 6		12		6
	
	// 1 2 3 4 5 
	long sum = 0;
	for(int i=1; i<=num; i++){
		sum += (num/i)*i;
	}
	
	printf("%ld", sum);
	
	return 0;
}
