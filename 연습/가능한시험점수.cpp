// SWEA 3752 가능한 시험 점수
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int N;
//int grade[100];
vector <int> grade;
int sel[100];
vector <int> list;

void recur(int len, int index, int limit){
	if(len == limit){
		int sum = 0;
		for(int i=0; i<limit; i++){
			sum += sel[i];
		}
//		if(list.size() == 0) list.push_back(sum);
		int start = 0;
		int end = list.size();
		int mid = (start+end)/2;
		while(start < end){
			mid = (start+end)/2;
			if(sum == list[mid]) return;
			else if(sum == list[mid-1]) return;
			if(sum < list[mid]) end = mid-1;
			else if(sum > list[mid]) start = mid+1;
		}
		list.insert(list.begin()+mid, sum);
//		list.push_back(sum);
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
		for(int i=0; i<N; i++){
			int num;
			scanf("%d", &num);
			grade.push_back(num);
//			scanf("%d", &grade[i]);
		}
		sort(grade.begin(), grade.end());
		for(int i=0; i<=N; i++){
			recur(0, 0, i);
//			for(int j=0; j<list.size(); j++) printf("%d ", list[j]);
//			printf("\n");
		}
		printf("#%d %d\n", test_case, list.size());
		list.clear();
	}
	
	return 0;
}
