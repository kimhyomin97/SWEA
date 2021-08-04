// 백준 14888 연산자 끼워넣기
#include <cstdio>
#include <vector>
using namespace std;

int n;
int arr[11];
int oper[4];

//int oper_list[11];
vector<int> oper_list;
bool visit[11] = {false,};
int select[11];

int max_ans = -99999999;
int min_ans = 99999999;
int temp = 0;
void recur(int len){
	if(len == n-1){
//		for(int i=0; i<len; i++) printf("%d ", select[i]);
//		printf("\n");
		int sum = arr[0];
		for(int i=0; i<len; i++){
			if(select[i] == 0) sum = sum + arr[i+1];
			if(select[i] == 1) sum = sum - arr[i+1];
			if(select[i] == 2) sum = sum * arr[i+1];
			if(select[i] == 3) sum = sum / arr[i+1];
		}
		if(sum > max_ans) max_ans = sum;
		if(sum < min_ans) min_ans = sum;
		return;
	}
	for(int i=0; i<n-1; i++){
		if(visit[i] == false){
//			printf("%d ", oper_list[i]);
			select[len] = oper_list[i];
			visit[i] = true;
			recur(len+1);	
			visit[i] = false;
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	for(int i=0; i<4; i++){
//		scanf("%d", &oper[i]);
		int num;
		scanf("%d", &num);
		for(int j=0; j<num; j++){
			if(i == 0) oper_list.push_back(0);
			if(i == 1) oper_list.push_back(1);
			if(i == 2) oper_list.push_back(2);
			if(i == 3) oper_list.push_back(3);
		}
	}
	
	recur(0);
	
	printf("%d\n", max_ans);
	printf("%d\n", min_ans);
	return 0;
}
