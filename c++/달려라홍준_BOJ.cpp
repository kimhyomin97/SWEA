// BOJ 1306 달려라 홍준
#include <iostream>
#define size (1 << 20)
using namespace std;

int list[size * 2];

int calc(int start, int end){
	int target = 0;
	while(start <= end){
		if(start % 2 == 1){
			if(target < list[start]) target = list[start];
			start++;
		}
		if(end % 2 == 0){
			if(target < list[end]) target = list[end];
			end--;
		}
		start /= 2;
		end /= 2;
	}
//	if(target < list[start]) target = list[start];
	return target;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> list[size+i];
	}
	
	for(int i=0; i<n; i++){ // tree update
		int index = size+i;
		while(index > 0){
			index /= 2;
			list[index] = list[index*2] > list[index*2+1] ? list[index*2] : list[index*2+1];
		}
	}
	int offset = m-1;
	for(int i=offset; i<=n-m; i++){
		int start = i-offset;
		int end = i+offset;
		cout << calc(start+size, end+size) << " ";
	}
	
	return 0;
} 
