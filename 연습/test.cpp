#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int n, left, right;
	scanf("%d%d%d", &n, &left, &right);
	vector <int> arr;
	for(int i=left; i<=right; i++){
		int num1 = i / n;
		int num2 = i % n;
		if(num1 > num2) arr.push_back(num1+1);
		else arr.push_back(num2+1);
	}
	for(int i=0; i<arr.size(); i++){
		printf("%d ", arr[i]);
	}
	return 0;
}
