#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
//	scanf("%d", &n);
	cin >> n;
	vector<int> list;
	for(int i=0; i<n; i++){
		int temp;
//		scanf("%d", &temp);
		cin >> temp;
		list.push_back(temp);
	}
	int m;
//	scanf("%d", &m);
	cin >> m;
	
	sort(list.begin(), list.end());
	for(int i=0; i<m; i++){
		int num;
//		scanf("%d", &num);
		cin >> num;
		int start = 0;
		int end = n-1;
		int mid;
		bool flag = false;
		while(start <= end){
			mid = (start + end) / 2;
			if(list[mid] == num) {
				flag = true;
				break;
			}
			else if(list[mid] > num) end = mid-1;
			else if(list[mid] < num) start = mid+1;
		}
//		if(flag) printf("1\n");
//		else printf("0\n");
		if(flag) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
