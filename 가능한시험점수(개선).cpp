// SWEA 3752 가능한 시험 점수
#include <cstdio>
#include <vector>
using namespace std;

int T;
int N;
vector <int> grade;
int sel[100];
bool visit[10001] = {false,};
int ans = 0;

void recur(int len, int index, int limit){
	if(len == limit){
		int sum = 0;
		for(int i=0; i<limit; i++){
			sum += sel[i];
		}
		if(visit[sum] == true) return;
		visit[sum] = true;
		ans++;
		return;
	}
	for(int i=index; i<N; i++){
		sel[len] = grade[i];
		recur(len+1, i+1, limit);
	}
}

int main(){
	scanf("%d", &T);
	for(int test_case = 1; test_case<=T; test_case++){
		scanf("%d", &N);
		ans = 0;
		for(int i=0; i<N; i++){
			int num;
			scanf("%d", &num);
			grade.push_back(num);
		}
		for(int i=0; i<=N; i++){
			recur(0, 0, i);
		}
		printf("#%d %d\n", test_case, ans);
	}
	
	return 0;
}
