#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

struct info{
	int dest;
	int cost;
};

bool operator < (info a, info b){
	return a.cost > b.cost;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int v, e;
	cin >> v >> e;
	int k;
	cin >> k;
	
//	info tree[v];
	vector<info> tree[20001];
	
	for(int i=0; i<e; i++){
		int a, b, c;
		cin >> a >> b >> c;
//		tree[a] = info{b, c};
		tree[a].push_back(info{b, c});
	}
	int dij[20001];
	for(int i=1; i<=v; i++) dij[i] = INF;
	priority_queue<info> pq;
	pq.push({k, 0});
	dij[k] = 0;
	
	while(pq.size() != 0){
		info now = pq.top();
		pq.pop();
		for(int i=0; i<tree[now.dest].size(); i++){
			if(dij[tree[now.dest][i].dest] > dij[now.dest] + tree[now.dest][i].cost){
				dij[tree[now.dest][i].dest] = dij[now.dest] + tree[now.dest][i].cost;
				pq.push({tree[now.dest][i].dest, dij[tree[now.dest][i].dest]});
			}
		}
	}
	
	for(int i=1; i<=v; i++){
		if(dij[i] == INF) cout<<"INF\n";
		else cout << dij[i] << "\n";
	}
	
	return 0;
}
