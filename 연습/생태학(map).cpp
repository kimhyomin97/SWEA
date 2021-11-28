// boj 4358 ปýลยวะ
#include <cstdio>
#include <string>
#include <map>
using namespace std;

int main(){
	char temp[31];
	map <string, int> tree;
	int size = 0;
	int len = 0;
	while(scanf(" %[^\n]s", temp) != EOF){
		bool flag = false;
		len++;
		if(tree.find(temp) != tree.end()){
			tree[temp]++;
		}
		else{
			tree.insert(make_pair(temp, 1));
		}
	}
	map <string, int> :: iterator iter;
	for(iter = tree.begin(); iter != tree.end(); iter++){
		printf("%s %.4lf\n", iter->first.c_str(), ((double)iter->second)/len*100);
	}
	return 0;
}  
