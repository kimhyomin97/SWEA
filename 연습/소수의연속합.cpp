// boj 1633 소수의 연속합
#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int num;
	scanf("%d", &num);
	vector <int> prime;
	int arr[num];
	int ans=0;
	for(int i=2; i<=num; i++){
		arr[i] = i;
	}
	for(int i=2; i<=num; i++){
		if(arr[i] == 0) continue;
		for(int j=i+i; j<=num; j+=i){
			arr[j] = 0;
		}
	}
	for(int i=2; i<=num; i++){
		if(arr[i] != 0) prime.push_back(arr[i]);
	}
	int size = prime.size();
	for(int i=0; i<size; i++){
		int sum=0;
		for(int j=i; j<size; j++){
			sum += prime[j];
			if(sum >= num){
				if(sum == num) ans++;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
} 
