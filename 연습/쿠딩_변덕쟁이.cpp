#include <cstdio>
#include <vector>
#include <queue>
//#include <algorithm>
using namespace std;

//vector <int> arr2;
//vector <long long> list;
struct ln{
	long long num;
};
bool operator < (ln a, ln b){
	return a.num > b.num;
}
int main(){
	int n, k;
	vector <int> arr1;
	priority_queue <ln> pq;
	scanf("%d %d", &n, &k);	
	for(int i=0; i<n; i++){
		int num;
		scanf("%d", &num);
		arr1.push_back(num);
	}
	for(int i=0; i<n; i++){
		int num;
		scanf("%d", &num);
//		arr2.push_back(num);
		for(int j=0; j<n; j++){
			long long res = arr1[j] * num;
//			list.push_back(res);
			pq.push({num});
		}	
	}
//	sort(arr1.begin(), arr1.end());
//	sort(arr2.begin(), arr2.end());
//	for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){
//			long long num = arr1[i] * arr2[j];
////			pq.push({num});
//			list.push_back(num);
//		}
//	}
	
//	sort(list.begin(), list.end());
//	printf("%lld", list[k-1]);
	
	for(int i=0; i<k; i++){
//		long long num = pq.top().num;
		pq.pop();
	}
	printf("%lld", pq.top());
	return 0;
}
