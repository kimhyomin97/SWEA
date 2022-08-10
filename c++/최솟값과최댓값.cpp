#include <iostream>
#define size (1 << 17)
using namespace std;

int minlist[size * 2];
int maxlist[size * 2];
	
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;	
	
	for(int i=0; i<n; i++){
		int num;
		cin >> num;
		minlist[size+i] = num;
		maxlist[size+i] = num;
	}
	
	for(int i=0; i<n; i++){
		int index = size + i;
		while(index > 0){
			index /= 2;
			minlist[index] = (minlist[index*2] < minlist[index*2+1]) ? minlist[index*2] : minlist[index*2+1];
			maxlist[index] = (maxlist[index*2] > maxlist[index*2+1]) ? maxlist[index*2] : maxlist[index*2+1];
		}
	}
	
	int temp = size;
	while(temp > 0){
		cout << minlist[temp] << " : " << maxlist[temp] << "\n";
		temp /= 2;
	}
	
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		if(a % 2 == 1){
			// ÇÑÄ­ ¿À¸¥ÂÊ ÀÌµ¿ 
		}
		if(b % 2 == 0){
			// ÇÑÄ­ ¿ŞÂÊ ÀÌµ¿ 
		}
	}
	
	
	return 0;
} 
