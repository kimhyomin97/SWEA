//쿠딩4번
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

//vector< vector<char> > map;
char map[10][10];
struct pos{
	int row;
	int col;
};
pos start;
pos dest;

int main(){
	int T;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		int n;
		scanf("%d", &n);
		vector <pos> a;
		vector <pos> b;
		vector <pos> c;
		vector <pos> d;
		for(int i=0; i<n; i++){
			scanf("%s", map[i]);
			for(int j=0; j<n; j++){
				if(map[i][j] == '*'){
					start.row = i;
					start.col = j;
				}
				if(map[i][j] == '#'){
					dest.row = i;
					dest.col = j;
				}
				if(map[i][j] == 'A'){
					a.push_back({i, j});
				}
				if(map[i][j] == 'B'){
					b.push_back({i, j});
				}
				if(map[i][j] == 'C'){
					c.push_back({i, j});
				}
				if(map[i][j] == 'D'){
					d.push_back({i, j});
				}
			}
		}
		int cnt = 0;
//		while(cnt<3){
//			for(int i=0; i<a.size(); i++){
//				
//			}	
//		}
		// next_permutation();
		
		
		
//		printf("%d %d %d %d\n", start.row, start.col, dest.row, dest.col);
//		for(int i=0; i<n; i++){
//			for(int j=0; j<n; j++){
//				printf("%c ", map[i][j]);
//			}
//			printf("\n");
//		}
	}
	
	return 0;
} 

//#include <bits/stdc++.h>
//using namespace std;
//int main(void){
// int T;
// cin >> T;
// while(T--) {
// int N;
// vector<pair<int,int>> v[4];
// pair<int,int> src, dst;
// cin >> N;
// for (int i = 0; i < N; i++) {
// for (int j = 0; j < N; j++) {
// char temp;
// cin >> temp;
// if (temp == 'A') v[0].push_back({i, j});
// if (temp == 'B') v[1].push_back({i, j});
// if (temp == 'C') v[2].push_back({i, j});
// if (temp == 'D') v[3].push_back({i, j});
// if (temp == '*') src = {i, j};
// if (temp == '#') dst = {i, j};
// }
// }
// string ans = "";
// int dist = 1e9;
// for (int i = 0; i < 4; i++) {
// int order[3] = {0, 1, 2};
// int d = 0;
// do {
//출제의도 : 익숙하다고 느껴지는 것을 제일 조심하자! 
// // src에서 v[i] 의 order대로 순차적으로 방문 후, dst까지 도착하는데
//걸리는 시간
// d = abs(src.first - v[i][order[0]].first) +
//abs(src.second - v[i][order[0]].second);
// for (int j = 1; j < 3; j++) {
// d += abs(v[i][order[j - 1]].first - v[i]
//[order[j]].first) +
// abs(v[i][order[j - 1]].second - v[i]
//[order[j]].second);
// }
// d += abs(v[i][order[2]].first - dst.first) + abs(v[i]
//[order[2]].second - dst.second);
// if (d < dist) {
// dist = d;
// if (i == 0)
// ans = "A DRAGON";
// if (i == 1)
// ans = "B DRAGON";
// if (i == 2)
// ans = "C DRAGON";
// if (i == 3)
// ans = "D DRAGON";
// }
// } while (next_permutation(order, order + 3));
// }
// cout << ans << '\n';
// }
// return 0;
//}
