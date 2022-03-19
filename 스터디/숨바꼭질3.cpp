// boj 13549 ¼û¹Ù²ÀÁú3
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	
	int check[100001];
	for(int i=0; i<100001; i++) check[i] = 987654321;
	queue<int> q;
	q.push(n);
	if(n > k) {
		printf("%d", n-k);
		return 0;
	}
	check[n] = 0;
	while(q.size() != 0){
		int now = q.front();
		q.pop();
		if(now == k){
			printf("%d", check[now]);
			return 0;
		}
		if(now+1<100001&&check[now+1] > check[now]+1){
			check[now+1] = check[now]+1;
			q.push(now+1);
		}
		if(now-1>=0&&check[now-1] > check[now]+1){
			check[now-1] = check[now]+1;
			q.push(now-1);
		}
		if(now*2 < 100001 && check[now*2] > check[now]){
			check[now*2] = check[now];
			q.push(now*2);
		}
	}
	printf("%d", check[k]);
	return 0;
} 
