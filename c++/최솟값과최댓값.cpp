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
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		int minval = 1000000001;
		int maxval = -1;
		a += size-1;
		b += size-1;
//		a += size;
//		b += size;
		int a2 = a;
		int b2 = b;
		while(a < b){
			if(a % 2 == 1){
				// ÇÑÄ­ ¿À¸¥ÂÊ ÀÌµ¿
				if(minlist[a] < minval) minval = minlist[a];
				if(maxlist[a] > maxval) maxval = maxlist[a];
				a++;
			}
			if(b % 2 == 0){
				// ÇÑÄ­ ¿ÞÂÊ ÀÌµ¿ 
				if(minlist[b] < minval) minval = minlist[b];
				if(maxlist[b] > maxval) maxval = maxlist[b];
				b--;
			}
			a /= 2;
			b /= 2;
		}
//		while(a2 < b2){
//			if(a2 % 2 == 1){
//				// ÇÑÄ­ ¿À¸¥ÂÊ ÀÌµ¿
//				if(maxlist[a2] > maxval) maxval = maxlist[a2];
//				a2++;
//			}
//			if(b2 % 2 == 0){
//				// ÇÑÄ­ ¿ÞÂÊ ÀÌµ¿ 
//				if(maxlist[b2] > maxval) maxval = maxlist[b2];
//				b2--;
//			}
//			a2 /= 2;
//			b2 /= 2;
//		}
		
		if(minlist[a] < minval) minval = minlist[a];
		if(maxlist[a] > maxval) maxval = maxlist[a];
//		if(maxlist[a2] > maxval) maxval = maxlist[a2];
		cout << minval << " " << maxval << "\n";
	}
	
	
	return 0;
} 
