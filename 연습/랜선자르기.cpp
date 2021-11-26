// boj 1654 랜선 자르기
#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int k, n;
	scanf("%d %d", &k, &n);
	long long sum=0;
	vector <int> arr;
	int size=0;
	for(int i=0; i<k; i++){
		int num;
		scanf("%d", &num);
		sum+=num;
		size++;
		arr.push_back(num);
	}
	long long min = 1;
	long long max = sum/n;
	long long ans = (min+max)/2;
	while(min <= max){
		int cnt=0;
		for(int i=0; i<size; i++){
			cnt += arr[i]/ans;
		}
		if(cnt < n) max = ans-1;
		if(cnt >= n) {
			min = ans+1;
		}
		ans = (min+max)/2;
	}
	printf("%lld", ans);
	
	return 0;
} 
