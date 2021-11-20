//Äíµù4¹ø
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
		while(cnt<3){
			for(int i=0; i<a.size(); i++){
				
			}	
		}
		
		
		
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
