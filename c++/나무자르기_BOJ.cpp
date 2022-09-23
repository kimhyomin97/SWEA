// BOJ 2805 나무 자르기
#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	long long list[n];
	long long h = 0;
	for(int i=0; i<n; i++){
		cin >> list[i];
		if(list[i] > h) h = list[i];
	}
	
	long long start = 0, end = h, mid;
	long long ans = 0;
	while(start <= end){
		mid = (start + end) / 2;
		long long sum = 0;
		for(int i=0; i<n; i++){
			if(list[i] > mid) sum += list[i] - mid;
		}
		if(sum >= m){
			ans = mid;
			start = mid + 1;
		}
		else end = mid - 1;
	}
	
	cout << ans;
	
	
	return 0;
} 
