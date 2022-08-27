// BOJ 가장 긴 증가하는 부분 수열 2 segment tree
#include <iostream>
#define size (1 << 20)
using namespace std;

int ans = 0;
int list[size * 2] = {0};

void update(int index, int num, int cnt){
	if(cnt > ans) ans = cnt;
	if(list[index] == 0){
		list[index] = num;
	}
	else{
		if(num <= list[index]) update(index*2, num, cnt);
		else update(index*2+1, num, cnt+1);
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
		update(1, num, 1);
	}
	
	cout << ans;
	
	return 0;
} 
