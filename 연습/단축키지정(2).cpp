// boj 1283 단축키 지정 
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	vector <string> arr[N];
	for(int i=0; i<N; i++){
		while(1){
			char temp[11];
			cin >> temp;
			arr[i].push_back(temp);
			if(temp == "\n") break;
		}
		
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<arr[i].size(); j++){
			printf("%s ", arr[i][j].c_str());
		}
		printf("\n");
	}
	
	return 0;
}
