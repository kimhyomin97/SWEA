// BOJ 2268 수들의 합7 다시 풀어본 버전
#include <iostream>
#define size (1 << 20)
using namespace std;

long long list[size * 2];

void update(int index, int num){
	list[index] = num;
	while(index > 0){
		index /= 2;
		list[index] = list[index * 2] + list[index * 2 + 1]; // index 1부터 시작 
	}
}

long long calc(int start ,int end){
	long long sum = 0;
	while(start <= end){
		if(start % 2 == 1){
			sum += list[start++];
		}
		if(end % 2 == 0){
			sum += list[end--];
		}
		start /= 2;
		end /= 2;
	}
//	sum += list[start];
	return sum;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 0){ // sum 
			if(b > c) cout << calc(c+size-1, b+size-1) << "\n";
			else cout << calc(b+size-1, c+size-1) << "\n";
		}
		if(a == 1){ // modify
			update(b+size-1, c);
		}
	}
	
	return 0;
} 
