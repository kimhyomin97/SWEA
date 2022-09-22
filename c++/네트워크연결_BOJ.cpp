// BOJ 1922 네트워크 연결 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct info{
	int cost;
	int dest;
};

bool operator < (info a, info b){
	return a.cost > b.cost;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int m;
	cin >> m;
	
	vector<info> tree[n+1];
	for(int i=0; i<m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({c, b});
		tree[b].push_back({c, a});
	}
	
	bool visit[n+1] = {false};
	priority_queue <info> pq;
	
	visit[1] = true;
	for(int i=0; i<tree[1].size(); i++) pq.push(tree[1][i]);
	
	int sum = 0;
	
	while(pq.size() != 0){
		info now = pq.top();
		pq.pop();
		if(visit[now.dest] == false){
			sum += now.cost;
			visit[now.dest] = true;
			for(int i=0; i<tree[now.dest].size(); i++){
				pq.push(tree[now.dest][i]);
			}
		}
	}
	
	cout << sum;
	
	
	return 0;
} 
