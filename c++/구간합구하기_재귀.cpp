// BOJ 2042 구간 합 구하기 (재귀)
#include <iostream>
#define size (1 << 17)
using namespace std;

long long tree[size * 2];

void update(int index, int num){
	index /= 2;
	if(index == 0) return;
	// 이부분 공부해봐야 된다 
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cou.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	
	for(int i=0; i<n; i++){
		cin >> tree[size + i];
	}
	for(int i=0; i<m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1){
			// update
		}
		if(a == 2){
			// sum
		}
	}
	
	return 0;
} 
