//#include <cstdio>
#include <iostream>
#define size (1 << 17)
using namespace std;

int max_val[size*2];
int min_val[size*2];

void update(int index){
	while(index != 0){
		index /= 2;
		max_val[index] = max_val[index*2] > max_val[index*2+1] ? max_val[index*2] : max_val[index*2+1];
		min_val[index] = min_val[index*2] > min_val[index*2+1] ? min_val[index*2+1] : min_val[index*2];
	}
}
int calc_max(int start, int end){
	int max_num = -1;
	while(start < end){
		if(start%2==1){
			if(max_val[start] > max_num){
				max_num = max_val[start];
			} 
			start++;
		}
		if(end%2==0){
			if(max_val[end] > max_num) {
				max_num = max_val[end];
			}
			end--;
		}
		start /= 2;
		end /= 2;
	}
	if(max_val[start] > max_num) max_num = max_val[start];
	return max_num;
}
int calc_min(int start, int end){
	int min_num = 1000000001;
	while(start < end){
		if(start%2==1){
			if(min_val[start] != 0 && min_val[start] < min_num){
				min_num = min_val[start];
			}
			start++;
		}
		if(end%2==0){
			if(min_val[end] != 0 && min_val[end] < min_num){
				min_num = min_val[end];
			}
			end--;
		}
		start /= 2;
		end /= 2;
	}
	if(min_val[start] != 0 && min_val[start] < min_num) min_num = min_val[start];
	return min_num;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		int num;
		cin >> num;
		max_val[size+i] = num;
		min_val[size+i] = num;
	}
	for(int i=n; i<size; i++){
		max_val[size+i] = -1;
		min_val[size+i] = 1000000001;
	}
	for(int i=0; i<n; i++){
		update(size+i);
	}
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		int min_ans = calc_min(size+a-1, size+b-1);
		int max_ans = calc_max(size+a-1, size+b-1);
		cout << min_ans << " " << max_ans <<"\n";
	}
	
	return 0;
}
