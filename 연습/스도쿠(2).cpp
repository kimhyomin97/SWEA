// boj 2580 ½ºµµÄí
#include <cstdio>
#include <vector>
using namespace std;

struct pos{
	int row;
	int col;
};
int map[9][9];
vector <pos> blank;

void check_row(int row, int col){
	bool temp[10] = {false,};
	int index;
	int cnt=0;
	for(int i=0; i<9; i++){
		if(map[row][i] == 0){
			cnt++;
		}
		else
			temp[map[row][i]] = true;
	}
	if(cnt >= 2) return;
	for(int i=1; i<10; i++){
		if(temp[i] == false) map[row][col] = i;
	}
	return;
}
void check_col(int row, int col){
	bool temp[10] = {false,};
	int index;
	int cnt=0;
	for(int i=0; i<9; i++){
		if(map[i][col] == 0){
			cnt++;
		}
		else
			temp[map[i][col]] = true;
	}
	if(cnt >= 2) return;
	for(int i=1; i<10; i++){
		if(temp[i] == false) map[row][col] = i;
	}
	return;
}
void check_box(int row, int col){
	bool temp[10] = {false,};
	int index_r;
	int index_c;
	int cnt=0;
	int offset_r = row/3;
	int offset_c = col/3;
	for(int i=offset_r*3; i<offset_r*3+3; i++){
		for(int j=offset_c*3; j<offset_c*3+3; j++){
			if(map[i][j] == 0){
				cnt++;
			}
			else
				temp[map[i][j]] = true;
		}
	}
	if(cnt >= 2) return;
	for(int i=1; i<10; i++){
		if(temp[i] == false) map[row][col] = i;
	}
}
int main(){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 0){
				blank.push_back({i, j});
			}
		}
	}
	int len = 0;
	while(blank.size() > 0){
		pos now = blank[len];
		check_row(now.row, now.col);
		if(map[now.row][now.col] != 0) {
			blank.erase(blank.begin()+len);
			continue;
		}
		check_col(now.row, now.col);
		if(map[now.row][now.col] != 0) {
			blank.erase(blank.begin()+len);
			continue;
		}
		check_box(now.row, now.col);
		if(map[now.row][now.col] != 0) {
			blank.erase(blank.begin()+len);
			continue;
		}
		len = (len+1) % blank.size();
	}
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
