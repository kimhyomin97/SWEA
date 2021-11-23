// boj 1283 단축키 지정
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	vector <string> arr;
	bool alpha[26] = {false,};
	
	for(int i=0; i<N; i++){
		char temp[11];
		scanf(" %[^\n]s", temp);
		arr.push_back(temp);
	}
	for(int i=0; i<arr.size(); i++){
		int index = -1;
		int first_idx = -1;
//		for(int j=0; j<arr[i].size(); j++){
//			if(arr[i][0] != ' ' && alpha[tolower(arr[i][j]) - 'a'] == false){
//				first_idx = j;
//			}
//		}
//		if(first_idx != -1){
//			alpha[tolower(arr[i][first_idx])] = true;
//			index = first_idx;
//		}
		if(arr[i][0] != ' ' && alpha[tolower(arr[i][0]) - 'a'] == false){
			alpha[tolower(arr[i][0]) - 'a'] = true;
			index = 0;
		}
		else{
			int space_idx = -1;
			for(int j=0; j<arr[i].size(); j++){
				if(arr[i][j] == ' '){
					space_idx = j;
					break;
				}
			}
			if(arr[i][space_idx] != ' ' && space_idx+1 < arr[i].size() && space_idx != -1 && alpha[tolower(arr[i][space_idx+1]) - 'a'] == false){
				alpha[tolower(arr[i][space_idx+1]) - 'a'] = true;
				index = space_idx+1;
			}
			else{
				for(int j=1; j<arr[i].size(); j++){
					if(arr[i][j] != ' ' && alpha[tolower(arr[i][j]) - 'a'] == false){
						alpha[tolower(arr[i][j]) - 'a'] = true;
						index = j;
						break;
					}
				}
			}
		}
		
		for(int j=0; j<arr[i].size(); j++){
			if(index != -1 && j==index){
				printf("[%c]", arr[i][j]);
			}
			else
				printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
} 
