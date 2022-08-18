// BOJ 12899 데이터 구조
#include <iostream>
#define size (1 << 21)
using namespace std;

int list[size * 2];

void update(int index, int num){
	if(list[index] == -1){
		update(index+1, num);
//		index++;
//		if(index%2 == 1){
//			update((index-1)*2, num);
//		}
//		else{
//			update(index+1, num);
//		}
//		return;
	}
	if(list[index] == 0) {
		list[index] = num;
		return;
	}
	if(list[index] > num){
		// 교체 
		int temp = list[index];
		list[index] = num;
		update(index, temp);
	}
	else{
		if(index%2 == 1){
			// 아래로 이동 
			if(index == 1) index++;
			update((index-1)*2, num); 
		}
		else{
			// 오른쪽으로 이동 
			update(index+1, num);
		}
	}
}

void calc(int index){
	if(list[index] == -1){
//		if(index%2==1){
//			if(index == 1) index++;
//			calc((index-1)*2);
//		}
//		else{
//			calc(index+1);
//		}
		calc(index+1);
	}
	else{
		cout << list[index] << "\n";
		list[index] = -1;
		return;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	list[0] = -1;
	cout << size << endl;
	for(int i=0; i<n; i++){
		int a, b;
		cin >> a >> b;
		if(a == 1){
			// update
			update(1, b);
		}
		if(a == 2){
			// calc
//			cout << calc(b) << "\n";
			calc(b);
		}
	}
	
	return 0;
} 
