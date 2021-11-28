// boj 4358 ปýลยวะ
#include <cstdio>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct info{
	string name;
	int cnt;
};
int main(){
	char temp[31];
	vector <info> tree;
	int size = 0;
	int len = 0;
	while(scanf(" %[^\n]s", temp) != EOF){
		bool flag = false;
		len++;
		for(int i=0; i<size; i++){
			if(tree[i].name == temp){
				flag = true;
				tree[i].cnt++;
				break;
			}
		}
		if(flag == false){
			tree.push_back({temp, 1});
			size++;
		}
	}
	for(int i=0; i<size; i++){
		printf("%s %.4lf\n", tree[i].name.c_str(), ((double)tree[i].cnt)/len*100);
	}
	return 0;
} 
