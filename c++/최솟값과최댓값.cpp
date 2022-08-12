// BOJ 2357 최솟값과 최댓값
#include <iostream>
#define size (1 << 17)
using namespace std;

int maxlist[size * 2];
int minlist[size * 2];

int getMax(int start, int end){
	int maxval = 0;
	while(start <= end){
		if(start % 2 == 1){
			if(maxval < maxlist[start]) maxval = maxlist[start];
			start++;
		}
		if(end % 2 == 0){
			if(maxval < maxlist[end]) maxval = maxlist[end];
			end--;
		}
		start /= 2;
		end /= 2;
	}
	return maxval;
}

int getMin(int start, int end){
	int minval = 1000000001;
	while(start <= end){
		if(start % 2 == 1){
			if(minval > minlist[start]) minval = minlist[start];
			start++;
		}
		if(end % 2 == 0){
			if(minval > minlist[end]) minval = minlist[end];
			end--;
		}
		start /= 2;
		end /= 2;
	}
	return minval;
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
		maxlist[size+i] = num;
		minlist[size+i] = num;
	}
	
	for(int i=0; i<n; i+=2){
		int index = size+i;
		while(index > 0){
			index /= 2;
			maxlist[index] = maxlist[index*2] > maxlist[index*2+1] ? maxlist[index*2] : maxlist[index*2+1];
			minlist[index] = minlist[index*2] < minlist[index*2+1] ? minlist[index*2] : minlist[index*2+1];
		}
	}
	
	for(int i=0; i<m; i++){
		int start, end; // 0이 아닌 1부터 시작 
		cin >> start >> end;
		cout << getMin(start+size-1, end+size-1) << " " << getMax(start+size-1, end+size-1) << "\n";
	}
	
	
	return 0;
}
