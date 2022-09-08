// 수 맞히기 게임 (지환 문제)
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long total_cnt = 0;
long long total_sum = 0;

int a, b, target;

int get_min(int start, int end){
	return max(start, (int)floor((start+end)/2 - 1));
}

int get_max(int start, int end){
	return min(end, (int)ceil((start+end)/2 + 1));
}

void recur(int start, int end, int num, int cnt){
	if(num == target){
		total_cnt++;
		total_sum += cnt;
		return;
	}
	else if(num > target){
		for(int i=get_min(start, num-1); i<=get_max(start, num-1); i++)
			recur(start, num-1, i, cnt+1);
	}
	else{
		for(int i=get_min(num+1, end); i<=get_max(num+1, end); i++)
			recur(num+1, end, i, cnt+1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> a >> b >> target;
		
		total_cnt = 0;
		total_sum = 0;
		for(int j=get_min(a, b); j<=get_max(a, b); j++) 
			recur(a, b, j, 1);
//			cout << "TEST " << a << " " << b << " " << j << " " << 1 << endl;

		cout << (double)total_sum / total_cnt << "\n";
	}
	
	return 0;
} 
