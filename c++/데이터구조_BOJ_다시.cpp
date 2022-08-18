// BOJ 12899 데이터 구조 segment tree
#include <iostream>
#define size (1 << 21)
using namespace std;

int list[size * 2];

void update(int index){
	while(index > 0){
		index /= 2;
		list[index] = list[index * 2] + list[index * 2 + 1];
	}
	return;
}

void calc(int index, int num){
	if(index > size){
		cout << index - size + 1 << "\n";
		return;
	} 
	// 왼쪽 자식값이 부모보다 작으면 값을 빼고 오른쪽으로 이동 
	if(list[index*2] < num){
		calc(index*2+1, num-list[index*2]);
	}
	// 왼쪽 자식값이 부모보다 크거나 같으면 왼쪽으로 이동
	else{
		calc(index*2, num);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int a, b;
		cin >> a >> b;
		if(a == 1){
			list[size + b-1] = 1;
			update(size + b-1);
		}
		if(a == 2){
			calc(1, b);
		}
	}
	
	return 0;
} 
