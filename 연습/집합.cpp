// boj 11723 С§Че
#include <iostream>
#include <string>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m;
	cin >> m;
	int bit = 0;
	string oper;
	int num;
	for(int i=0; i<m; i++){
		cin >> oper;
		if(oper == "add") {
//			scanf("%d", &num);
			cin >> num;
			bit |= (1<<num);
		}
		else if(oper == "remove"){
//			scanf("%d", &num);
			cin >> num;
			bit &= ~(1<<num);
		}
		else if(oper == "check"){
//			scanf("%d", &num);
			cin >> num;
			if(bit & (1<<num)) 
//				printf("1\n");
				cout << 1 << '\n';
			else
//				printf("0\n");
				cout << 0 << '\n';
		}
		else if(oper == "toggle"){
//			scanf("%d", &num);
			cin >> num;
			bit ^= (1<<num);
		}
		else if(oper == "all"){
			bit = (1<<21)-1;
		}
		else if(oper == "empty"){
			bit = 0;
		}
	}
	
	
	return 0;
} 
