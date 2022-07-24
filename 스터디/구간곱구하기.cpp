#include <cstdio>
#include <iostream>
//#include <vector>
#define size (1 << 20)
#define offset 1000000007
using namespace std;

long long tree[2*size];
//int offset = 1000000007;

void update(int num){
	while(num != 0){
		num /= 2;
		tree[num] = (tree[num*2] * tree[num*2+1])%offset;
	}
}

long long calc(int start, int end){
	int sum = 1;
	while(start <= end){
		if(start % 2 == 1){
			sum = (sum * tree[start++])%offset;
		}
		if(end % 2 == 0){
			sum = (sum * tree[end--])%offset;
		}
		start /= 2;
		end /= 2;
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
//	scanf("%d %d %d", &n, &m, &k);
	for(int i=0; i<n; i++){
		cin >> tree[size+i];
//		scanf("%d", &tree[size+i]);
	}
	for(int i=0; i<n; i++){
		update(size+i);
	}
	
	for(int i=0; i<m+k; i++){
		int a, b, c;
		cin >> a >> b >> c;
//		scanf("%d %d %d", &a, &b, &c);
		if(a == 1){
			tree[size+b-1] = c;
			update(size+b-1);
		}
		else if(a == 2){
			cout << calc(size+b-1, size+c-1) << "\n";
//			printf("%lld\n", calc(size+b-1, size+c-1));
		}
	}
	
	
	return 0;
} 
