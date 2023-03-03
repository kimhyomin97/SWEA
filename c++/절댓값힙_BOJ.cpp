#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct info {
	int abs;
	int value;
};

bool operator < (info a, info b){
	if(b.abs == a.abs){
		return b.value < a.value;
	}
	return b.abs < a.abs;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	priority_queue<info> pq;
	
	for(int i=0; i<n; i++){
		int num;
		cin >> num;
		if(num == 0){
			if(pq.empty()){
				cout << "0\n";
				continue;
			}
			info temp = pq.top();
			pq.pop();
			cout << temp.value << "\n";
		}
		else {
			pq.push({abs(num), num});
		}
	}
	
	return 0;
}
