// boj 16947 서울지하철2호선
#include <cstdio>
#include <vector>
using namespace std;

int num;
vector <int> tree[3001];
int check[3001] = {0,};
int answer[3001] = {0,};

void recur(int now, int before, int cnt, int start){
	for(int i=0; i<tree[now].size(); i++){
		if(tree[now][i] != before){
			if(check[tree[now][i]] == -1){
				recur(tree[now][i], now, cnt+1, start);
			}
			else if(check[tree[now][i]] == 0){
//				check[start] = cnt;
				answer[start] = cnt;
				return;
			}
		}
	}
}

int main(){
	scanf("%d", &num);
	for(int i=0; i<num; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	for(int i=1; i<=num; i++){
		for(int j=1; j<=num; j++){
			int size = tree[j].size();
			for(int k=0; k<tree[j].size(); k++){
				if(check[tree[j][k]] == -1) size--;
			}
			if(size == 1) check[j] = -1;
		}
	}
	
	for(int i=1; i<=num; i++){
		if(check[i] == -1){
			recur(i, i, 1, i);
		}
	}
	
	for(int i=1; i<=num; i++){
		printf("%d ", answer[i]);
	}
	
	return 0;
} 
