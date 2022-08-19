// BOJ 1572 Áß¾Ó°ª segment tree
#include <iostream>
#define size (1 << 18)
using namespace std;

int tree[size * 2];
long long sum = 0;

void update(int index){
	while(index > 0){
		index /= 2;
		tree[index] = tree[index * 2] + tree[index * 2 + 1];
	}
}

void calc(int index, int target){
	if(index >= size){
//		return index-size;
		sum += index-size;
		return;
	}
	if(tree[index*2] < target){
		calc(index*2+1, target - tree[index*2]);
	}
	else{
		calc(index*2, target);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	int list[n];
	for(int i=0; i<n; i++){ 
		int num;
		cin >> num;
		list[i] = num;
		tree[size+num]++;
		update(size+num);
		if(i < k-1) continue;
//		sum += calc(1, (k+1)/2);
		calc(1, (k+1)/2);
		tree[size+list[i-k+1]]--;
		update(size+list[i-k+1]);
	}
	cout << sum;
	return 0;
} 
