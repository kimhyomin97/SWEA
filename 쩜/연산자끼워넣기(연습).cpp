//// 백준 연산자 끼워넣기 백트래킹 사용
//#include <cstdio>
//#include <vector>
//using namespace std;
//
//int n;
//vector<int> arr;
//int oper[4];
//int mymax = -99999999;
//int mymin = 99999999;
//
//void recur(int len, int sum){
//	if(len == n-1) {
//		if(sum > mymax) mymax = sum;
//		if(sum < mymin) mymin = sum;
//	}
//	len++;
//	if(oper[0]>0){
//		oper[0]--;
//		recur(len, sum + arr[len]);
//		oper[0]++;
//	}
//	if(oper[1]>0){
//		oper[1]--;
//		recur(len, sum - arr[len]);
//		oper[1]++;
//	}
//	if(oper[2]>0){
//		oper[2]--;
//		recur(len, sum * arr[len]);
//		oper[2]++;
//	}
//	if(oper[3]>0){
//		oper[3]--;
//		recur(len, sum / arr[len]);[]
//		oper[3]++;
//	}
//}
//
//int main(){
//	scanf("%d", &n);
//	for(int i=0; i<n; i++){
//		int num;
//		scanf("%d", &num);
//		arr.push_back(num);
//	}
//	for(int i=0; i<4; i++){
//		scanf("%d", &oper[i]);
//	}
//	
//	recur(0, arr[0]);
//	printf("%d\n", mymax);
//	printf("%d\n", mymin);
//	return 0;
//} 
#include <cstdio>

int arr[5] = {1, 2, 3, 4, 5};
int visit[5] = {false,};
int select[5];

void recur(int len){
	if(len == 5){
		for(int i=0; i<len; i++) printf("%d ", select[i]);
		printf("\n");
		return;
	}		
	for(int i=0; i<5; i++){
		if(visit[i] == false){
			select[len] = i;
			visit[i] = true;
			recur(len+1);
			visit[i] = false;
		}
	}
}

int main(){
	
	recur(0);
	
}
