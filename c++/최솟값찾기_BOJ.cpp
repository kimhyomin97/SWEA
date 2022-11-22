// BOJ 11003 최솟값 찾기
#include <iostream>
#define SIZE (1 << 23)
using namespace std;

int list[SIZE * 2];

void update(int index){
	while(index > 0){
		index/=2;
		list[index] = list[index*2] < list[index*2+1] ? list[index*2] : list[index*2+1];
	}
}

int query(int start, int end){
	int num = list[start];
	while(start <= end){
		if(start % 2 == 1){
			if(num > list[start]) num = list[start];
			start++;
		}
		if(end % 2 == 0){
			if(num > list[end]) num = list[end];
			end--;
		}
		start /= 2;
		end /= 2;
	}
	return num;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, l;
	cin >> n >> l;
//	for(int i=0; i<SIZE*2; i++) {
//		list[i]=1000000001;
//	}
	for(int i=0; i<n; i++){
		int num;
		cin >> num;
		list[SIZE+i] = num;
		update(SIZE+i);
	}
	
	for(int i=0; i<n; i++){
		if(i-l+1 < 0) cout << query(SIZE+0, SIZE+i);
		else cout << query(SIZE+i-l+1, SIZE+i);
		cout << " ";
	}
	
	return 0;
} 
