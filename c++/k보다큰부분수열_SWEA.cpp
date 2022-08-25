// SWEA 3311 K보다 큰 부분 수열 세그먼트 트리
#include <iostream>
#define size (1 << 17)
using namespace std;

void update(int index, int list[]){
	while(index > 0){
		index /= 2;
		
	}
}

void query(int left, int right, int num, int list[]){
	// left부터 right까지 num보다 큰 원소의 개수를 출력
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int testcase;
	cin >> testcase;
	
	for(int T=1; T<=testcase; T++){
		int n;
		cin >> n;
		
		int list[size * 2] = {0};
		for(int i=0; i<n; i++){
			cin >> list[i+size];
		}
		for(int i=0; i<n; i+=2){
			update(i, list);
		}
		int m;
		cin >> m;
		cout << size;
		cout << "#" << T << " ";
		for(int i=0; i<m; i++){
			int l, r, k;
			cin >> l >> r >> k;
			
		}
		cout << "\n";
	}
	
	return 0;
} 
