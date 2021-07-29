#include <stdio.h>
#include <iostream>
using namespace std;

int map[100][100];
char line[100][101];
bool visit[100][100] = { false, };
struct ps {
	int x;
	int y;
};
ps start, dest;
int res = 100000000;
int num;

void dfs(int row, int col, int num) {
	if (row == dest.x && col == dest.y) {
		if (res > num) res = num;
		return;
	}
	if (row >= 0 && row < num && col >= 0 && col < num) return;
	else {
		num += map[row][col];
		dfs(row + 1, col, num);
		dfs(row - 1, col, num);
		dfs(row, col + 1, num);
		dfs(row, col - 1, num);
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	// int t;
	// scanf("%d", &t);
	for (int i = 0; i < 1; i++) {
		scanf_s("%d", &num);
		for (int i = 0; i < num; i++) {
			//cin >> line[i];
			for (int j = 0; j < num; j++) {
				scanf_s("%1d", &map[i][j]);
			}
		}
		start = { 0, 0 };
		dest = { num - 1, num - 1 };
		
		dfs(0, 0, 0);
		printf("%d", res);

		//for (int i = 0; i < num; i++) {
		//	for (int j = 0; j < num; j++) {
		//		printf("%d", map[i][j]);
		//		//printf("%c", line[i][j]);
		//	}
		//	printf("\n");
		//}
	}

	return 0;
}