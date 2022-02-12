// boj 1920 수찾기 (다시)
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, m;
	scanf("%d", &n);
	vector<int> list;
	for(int i=0; i<n; i++){
		int num;
		scanf("%d", &num);
		list.push_back(num);
	}
	sort(list.begin(), list.end());
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		int num;
		scanf("%d", &num);
		
		int left = 0, right = n-1, mid;
		bool flag = true;
		while(left <= right){
			mid = (left + right) / 2;
			if(list[mid] == num){
				flag = false;
				printf("1\n");
				break;
			}
			else if(list[mid] > num) right = mid-1;
			else if(list[mid] < num) left = mid+1;
		}
		if(flag) printf("0\n");
	}
	
	return 0;
} 
