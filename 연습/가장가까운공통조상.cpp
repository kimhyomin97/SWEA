// boj 3584 가장 가까운 공통 조상
#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int test=0; test<T; test++){
		int n;
		scanf("%d", &n);
		vector <int> tree[n+1];		
		for(int i=0; i<n-1; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			tree[b].push_back(a);
		}
		int num1, num2;
		scanf("%d %d", &num1, &num2);
		vector <int> first;
		vector <int> second;
		first.push_back(num1);
		second.push_back(num2);
		while(tree[num1].size() != 0){
			num1 = tree[num1][0];
			first.push_back(num1);
		}
		while(tree[num2].size() != 0){
			num2 = tree[num2][0];
			second.push_back(num2);
		}
		int ans = -1;
		for(int i=0; i<first.size(); i++){
			int point1 = first[i];
			for(int j=0; j<second.size(); j++){
				int point2 = second[j];
				if(point1 == point2) {
					ans = point1;
					break;
				}
			}
			if(ans != -1) break;
		}
		printf("%d\n", ans);
	}
	
	return 0;
} 
