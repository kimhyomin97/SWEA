// BOJ 2493 ž  
#include <iostream>
#include <vector>
using namespace std;

struct info {
	int index;
	int value;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<info> stack;
	vector<int> ans;
	
	for(int i=0; i<n; i++){
		int num;
		cin >> num;
		bool flag = true;
		int offset = 0;
		while(stack.size() > 0){
			info now = stack.back();
			stack.pop_back();
			if(now.value >= num){
				flag = false;
				ans.push_back(now.index+1);
				stack.push_back(now);
				break;
			}
		}
		stack.push_back({i, num});
		if(flag) ans.push_back(0);
	}
	
	for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";	
	
	return 0;
}
