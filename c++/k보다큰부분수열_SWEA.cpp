// SWEA 3311 K보다 큰 부분 수열 세그먼트 트리
#include <iostream>
#define size (1 << 17)
using namespace std;

void update(int index, int list[]){
	while(index > 0){
		index /= 2;
		list[index] = list[index*2] < list[index*2+1] ? list[index*2] : list[index*2+1];
	}
}

int query(int left, int right, int num, int list[]){
	// left부터 right까지 num보다 큰 원소의 개수를 출력
	int cnt = 0;
	while(left > 0){
		if(left%2==1){
			
		}
	}
//	while(left < right){
//		if(left % 2 == 1) {
//			if(list[left] > num) cnt++;
//			left++;
//		}
//		if(right % 2 == 0) {
//			if(list[right] > num) cnt++;
//			right--;
//		}
//		left /= 2;
//		right /= 2;
//	}
	return cnt;
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
		cout << "#" << T << " ";
		for(int i=0; i<m; i++){
			int l, r, k;
			cin >> l >> r >> k;
			cout << query(l, r, k, list) << " ";
		}
		cout << "\n";
	}
	
	return 0;
} 
