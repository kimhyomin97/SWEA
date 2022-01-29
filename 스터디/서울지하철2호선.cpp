// boj 16947 서울 지하철 2호선
#include <cstdio>
#include <vector>
using namespace std;

int num;
vector <int> tree[3001];

// 6
// 1 2
// 2 3
// 2 4
// 3 5
// 4 5
// 5 6

vector <int> point;
int answer[3001] = {0,}; 

void recur(int now, int before, int cnt){
	answer[now] = cnt;
	for(int i=0; i<tree[now].size(); i++){
		if(tree[now][i] != before){
			bool flag = true;
			for(int j=0; j<point.size(); j++){
				if(tree[now][i] == point[j]) flag = false;
			}
			if(flag) recur(tree[now][i], now, cnt+1);
		}
	}
}

void set_zero(int now, int before){
	answer[now] = 0;
	for(int i=0; i<tree[now].size(); i++){
		if(tree[now][i] != before){
			bool flag = true;
			for(int j=0; j<point.size(); j++){
				if(tree[now][i] == point[j]) flag = false;
			}
			if(flag) set_zero(tree[now][i], now);
		}
	}
}

void check(int now, int before){
	for(int i=0; i<tree[now].size(); i++){
		if(tree[now][i] != before){
			for(int j=0; j<point.size(); j++){
				if(tree[now][i] == point[j]) {
					set_zero(now, now);
					return;
				}
			}
			check(tree[now][i], now);
		}
	}
}

bool cycle(int now, int before){
	if(tree[now].size() == 1) return false;
	for(int i=0; tree[now].size(); i++){
		if(tree[now][i] != before){
			for(int j=0; j<point.size(); j++){
				if(tree[now][i] == point[j]){
					return true;
				}
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
		if(tree[i].size() >= 3){
			point.push_back(i);
		}
	}
	// 싸이클이 맞는지 검증
//	for(int i=0; i<point.size(); i++){
//		for(int j=0; j<tree[point[i]].size(); j++){
//			bool test = cycle(tree[point[i]][j], tree[point[i]][j]);
//			if(test == false) printf("%d\n", j);
//			
//			if(test == false) point.erase(point.begin()+i);
//		}
//	} 

	
	// 싸이클 밖에있는 노드 거리값계산 
	for(int i=0; i<point.size(); i++){
		recur(point[i], point[i], 0);
	}
	
	// 싸이클 내부에 있는 노드 거리값 0으로 설정 
	for(int i=0; i<point.size(); i++){
		check(point[i], point[i]);
	}
	
	for(int i=1; i<=num; i++){
		printf("%d ", answer[i]);
	}
	
	return 0;
} 
