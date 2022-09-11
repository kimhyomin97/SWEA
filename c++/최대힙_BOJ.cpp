// BOJ 11279 최대힙
#include <iostream> 
#include <queue> 
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	priority_queue<int> pq;
	
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		if(x == 0){
			// 값 출력
			if(pq.size() == 0) cout << 0 << "\n";
			else{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else{
			// 값 추가
			 pq.push(x);
		}
	}
	
	return 0;
}
