// boj 2749 피보나치 수3 G2
#include <cstdio>
#include <vector>
using namespace std;
// 피사노 주기의 이해

int main(){
	unsigned long long num;
	scanf("%llu", &num);
	vector <int> list;
	
	list.push_back(0);
	list.push_back(1);	
	
	for(int i=2; i<1500000; i++){
		list.push_back((list[i-2]+list[i-1])%1000000);
	}
	printf("%d", list[num%1500000]);
	
	return 0;
} 
