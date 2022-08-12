// BOJ 2268 수들의 합7 세그먼트트리 
// 재귀문으로 짜는 방법 생각해봐야된다 
#include <iostream> 
#define size (1 << 20)
using namespace std;

long long tree[size * 2];

void update(int index, int num){
	tree[index] = num;
	while(index > 0){
		index /= 2;
		tree[index] = tree[index*2] + tree[index*2 + 1];
	}
}

long long calc(int start, int end){
	long long sum = 0;
	while(start < end){
		if(start % 2 == 1){
			sum += tree[start];
			start++;
		}
		if(end % 2 == 0){
			sum += tree[end];
			end--;
		}
		start /= 2;
		end /= 2;
	}
	sum += tree[start];
	return sum;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 0){
			// sum
			b--;c--;
			if(b > c) cout << calc(c+size, b+size) << "\n";
			else cout << calc(b+size, c+size) << "\n";
		}
		else if(a == 1){
			// update
			b--;
			update(size + b, c);
		}
	}
	return 0;
}
