#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	vector <int> arr;
	for(int i=1; i<=n; i++) arr.push_back(i);
	
	int size = n;
	int offset = k-1;
	
	while(size!=1){
		printf("%d\n", arr[(offset%size)]);
		arr.erase(arr.begin()+(offset%size));
		size--;
		offset+=k-1;
	}
	int answer = arr[0];
	printf("%d", answer);
	
	return 0;
}
