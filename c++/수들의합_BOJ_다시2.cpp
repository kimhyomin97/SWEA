// BOJ 수들의 합 7 다시2
#include <iostream>
#define size (1 << 20)
using namespace std;

long long tree[size * 2];

void update(int index, int num){
	tree[index] = num;
	while(index > 0){
		index /= 2;
		tree[index] = tree[index*2] + tree[index*2+1]; // 2의 n승부터 시작함
		// 예를들어
		// 8부터 시작하기 때문에 list[4] = list[8] + list[9] 이런 형식!!!!! 
	}
}

long long calc(int start, int end){
	long long sum = 0;
	
	while(start <= end){
		if(start % 2 == 1) sum += tree[start++];
		if(end % 2 == 0) sum += tree[end--];
		start /= 2;
		end /= 2;
	}
	
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
