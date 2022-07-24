#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info{
	int value;
	int weight;
};

bool operator < (info a, info b){
	return a.value < b.value;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k; // n : 물품의 개수, k : 무게 제한 
	cin >> n >> k;
	
	vector<info> list;
	for(int i=0; i<n; i++){
		int w, v; // w : 물건의 무게 ,v : 물건의 가치
		cin >> w >> v;
		list.push_back({v, w});
	} 
	sort(list.begin(), list.end()); // 물건을 가치 기준으로 정렬 (오름차순)
	
	int dp[k][2]; // 무게제한 만큼의 길이를 갖는 dp배열 [i][0] : 가방의 무게, [i][1] : 가방의 가치 
	for(int i=0; i<k; i++) {
		dp[i][0] = 0;
		dp[i][1] = 0;
	}
	int answer = 0;
	
	for(int i=1; i<=k; i++){
		for(int j=0; j<n; j++){
			if(list[j].weight > i){
//				cout << dp[i][0] << " : a " << dp[i][1] << "\n";
//				dp[i][0] = dp[i-1][0];
//				dp[i][1] = dp[i-1][1];
//				cout << dp[i][0] << " : b " << dp[i][1] << "\n";
			}
			else{
				if(dp[i][1] < dp[i-list[j].weight][1] + list[j].value){
					dp[i][0] = dp[i-list[j].weight][0] + list[j].weight;
					dp[i][1] = dp[i-list[j].weight][1] + list[j].value;
					if(answer < dp[i][1]) answer = dp[i][1];
				}
				else{
					dp[i][0] = dp[i-1][0];
					dp[i][1] = dp[i-1][1];
				}
			}
		}
	}
	
	cout << answer << "\n";
//	for(int i=0; i<k; i++){
//		cout << dp[i][0] << " " << dp[i][1] << "\n";
//	}
	return 0;
}
