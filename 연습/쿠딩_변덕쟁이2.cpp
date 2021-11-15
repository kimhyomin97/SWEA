#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, k;
	vector <int> arr1;
	vector <int> arr2;
//	vector <long long> list;
	long long ans;
	
	scanf("%d %d", &n, &k);	
	for(int i=0; i<n; i++){
		int num;
		scanf("%d", &num);
		arr1.push_back(num);
	}
	for(int i=0; i<n; i++){
		int num;
		scanf("%d", &num);
		arr2.push_back(num);
	}
	if(k == 1){
		ans = arr1[0] * arr2[0];
		printf("%lld", ans);
		return 0;
	}
	int cnt1=0, cnt2=0;
	for(int i=1; i<k; i++){
		if(cnt1 == n-1) {
			cnt2++;
		}
		else if(cnt2 == n-1) {
			cnt1++;
		}
		else{
			long long num1 = arr1[cnt1+1] * arr2[cnt2];
			long long num2 = arr1[cnt1] * arr2[cnt2+1];
			if(num1 > num2) cnt2++;
			else {
				cnt1++;
				cnt2=0;
			}
		}
	}
//	printf("%d %d\n", arr1[cnt1], arr2[cnt2]);
	ans = arr1[cnt1] * arr2[cnt2];
	printf("%lld", ans);
//	sort(list.begin(), list.end());
//	printf("%lld", list[k-1]);
	
	return 0;
}
