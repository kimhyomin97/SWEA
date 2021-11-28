// boj 1655 가운데를 말해요
#include <cstdio>
#include <queue>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	priority_queue <int, vector<int>, less<int> > left;
	priority_queue <int, vector<int>, greater<int> > right;
	int l_size = 0, r_size = 0;
	for(int i=0; i<n; i++){
		int num;
		scanf("%d", &num);
		if(l_size == r_size){
			left.push(num);
			l_size++;
		}
		else{
			right.push(num);
			r_size++;
		}
		if(l_size != 0 && r_size != 0){
			if(left.top() > right.top()){
				int temp1 = left.top();
				int temp2 = right.top();
				left.pop();
				right.pop();
				left.push(temp2);
				right.push(temp1);
			}
		}
		printf("%d\n", left.top());
	}
	return 0;
} 
