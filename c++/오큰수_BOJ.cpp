// BOJ 17298 ¿ÀÅ«¼ö
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> arr;
	vector<int> ans;
	stack<int> st;
	
	for(int i=0; i<n; i++){
		int num;
		cin >> num;
		arr.push_back(num);
	}
	
	for(int i=0; i<n; i++){
		int num = arr.back();
		arr.pop_back();
		st.push(num);
		if(st.size() == 0){
			ans.push_back(-1);
		}
		else{
			while(st.size()){
				int temp = st.top();
				if(temp > num) {
					ans.push_back(temp);
					break;
				}
				else{
					st.pop();
				}
			}
			if(st.size() == 0) ans.push_back(-1);
			st.push(num);
		}
	}
	
	for(int i=0; i<n; i++){
		printf("%d ", ans.back());
		ans.pop_back();
	}
	
	return 0;
} 
