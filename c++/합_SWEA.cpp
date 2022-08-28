// SWEA 5642 гу segment tree
#include <iostream>
#include <cstring>
#define size (1 << 17)
using namespace std;

int ans;
int list[size * 2];

void update(int index, int list[]){
	while(index > 1){
		index /= 2;
		list[index] = list[index*2] + list[index*2+1];
	}
}

void calc(int index, int list[]){
	if(list[index] > ans) ans = list[index];
	if(index < size){
		calc(index*2, list);
		calc(index*2+1, list);
	}
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
		memset(list, 0, sizeof(list));
		for(int i=0; i<n; i++){
			cin >> list[size + i];
		}
		for(int i=0; i<n; i+=2){
			update(size+i, list);
		}
		ans = 0;
		calc(1, list);
		cout << "#" << T << " " << ans << "\n";
	}
	
	return 0;
} 
