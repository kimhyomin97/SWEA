// BOJ 2580 ½ºµµÄí
#include <iostream>
#include <vector>
using namespace std;

struct position{
	int row;
	int col;
};
static int map[9][9];
static int answer[9][9];
static vector<position> blank;
bool found = false;

bool check(int row, int col, int num){
	for(int i=0; i<9; i++){
		if(map[i][col] == num || map[row][i] == num) return false;
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(map[(row/3)*3+i][(col/3)*3+j] == num) return false;
		}
	}
	return true;
}

void recur(){
	if(blank.size() == 0) {
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				answer[i][j] = map[i][j];
			}
		}
		found = true;
		return;	
	}
	position target = blank.back();
	for(int i=1; i<=9; i++){
		if(check(target.row, target.col, i)){
			map[target.row][target.col] = i;
			blank.pop_back();
			recur();
			blank.push_back(target);
			map[target.row][target.col] = 0;
		}
		if(found) return;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cin >> map[i][j];
			if(map[i][j] == 0) blank.push_back({i, j});
		}
	}

	recur();
	
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
	
	
	
	return 0;
} 
