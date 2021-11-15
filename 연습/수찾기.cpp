#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr;
vector<int> arr2;
int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int num;
		scanf("%d", &num);
		arr.push_back(num);
	}
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		int num;
		scanf("%d", &num);
		arr2.push_back(num);
	}
//	for(int i=0; i<m; i++){
//		bool flag = false;
//		for(int j=0; j<n; j++){
//			if(arr2[i] == arr[j]){
//				flag = true;
//				break;
//			}
//		}
//		if(flag == true) printf("1\n");
//		else printf("0\n");
//	}
	sort(arr.begin(), arr.end());
	
	for(int i=0; i<m; i++){
		int start = 0, end = n, mid;
		bool flag = false;
		while(start <= end){
			mid = (start + end)/2;
			if(arr2[i] == arr[mid]){
				flag = true;
				break;
			}
			else if(arr2[i] > arr[mid]){
				start = mid+1;
			}
			else if(arr2[i] < arr[mid]){
				end = mid-1;
			}
		}
		if(flag == true) printf("1\n");
		else printf("0\n");
	}
	
	return 0;
}
