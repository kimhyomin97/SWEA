// BOJ 12015 가장 긴 증가하는 부분 수열 2 segment tree
#include <iostream>
#define size (1 << 20)
using namespace std;

int tree[size * 2];
int ans = 0;

void update(int level, int index, int num){
	 if(tree[index] == 0){
	 	if(level > ans) ans = level;
		tree[index] = num;
	 	return;
	 }
	 if(num <= tree[index]){
	 	update(level+1, index*2, num);
	 }
	 else{
	 	update(level+1, index*2+1, num);
	 }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int num;
		cin >> num;
		update(1, 1, num);
	}
	cout << ans;
	return 0;
} 
