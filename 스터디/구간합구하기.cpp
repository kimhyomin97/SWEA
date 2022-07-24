#include <cstdio>
#include <vector>
#define size (1<<20)
using namespace std;

long long tree[2*size];

void update(int index){
	while(index != 0){
		index /= 2;
		tree[index] = tree[index*2] + tree[index*2+1];
	}
//	if(index == 0) return;
//	index /= 2;
//	tree[index] = tree[index*2] + tree[index*2+1];
}

long long calc(long long start, long long end){
	long long sum = 0;
	while(start <= end){
		if(start % 2 == 1){
			sum += tree[start++];
		}
		if(end % 2 == 0){
			sum += tree[end--];
		}
		start /= 2;
		end /= 2;
	}
//	sum += tree[start];
//	sum += tree[end];
	return sum;
}

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	
	for(int i=0; i<n; i++){
		scanf("%lld", &tree[size+i]);
	}
	for(int i=0; i<n; i++){
		update(size+i);
	}
	for(int i=0; i<m+k; i++){
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		if(a==1){
			// b번째 수를 c로 변경
			tree[size+b-1] = c;
			update(size+b-1);
		}
		else if(a==2){
			// b번째부터 c번째 수까지의 합을 출력
			printf("%lld\n", calc(size+b-1, size+c-1));
		}
	}
	
	return 0;
}
