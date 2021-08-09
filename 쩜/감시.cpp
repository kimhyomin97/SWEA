// 백준 15683 감시
// 그리디한 방법으로 접근
// 예외가 발생한다
// 4 6
// 2 6 0 3 0 2
// 0 0 0 0 0 0
// 0 0 0 0 0 0
// 0 0 0 0 6 1
// 그리디한 방법으로는 정답을 찾을 수 없다
#include <cstdio>

int n, m;
int map[8][8];
int ans;

void check(int row, int col, int dr, int dc){
    while(1){
        row += dr;
        col += dc;
        if(row < 0 || col < 0 || row >= n || col >= m) break;
        if(map[row][col] == 6) break;
        else if (map[row][col] == 0) map[row][col] = -1;
    }
}

int find(int row, int col, int dr, int dc){
    int res = 0;
    while(1){
        row += dr;
        col += dc;
        if(row < 0 || col < 0 || row >= n || col >= m) break;
        if(map[row][col] == 6) break;
        else if(map[row][col] == 0) res++;
    }
    return res;
}

void solve(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 1){
                int num1 = find(i, j, 1, 0);
                int num2 = find(i, j, -1, 0);
                int num3 = find(i, j, 0, 1);
                int num4 = find(i, j, 0, -1);
                int max = 0;
                int index = 0;
                if(max < num1) {
                    max = num1;
                    index = 1;
                }
                if(max < num2) {
                    max = num2;
                    index = 2;
                }
                if(max < num3) {
                    max = num3;
                    index = 3;
                }
                if(max < num4) {
                    max = num4;
                    index = 4;
                }
                if(max > 0){
                    if(index == 1) check(i, j, 1, 0);
                    if(index == 2) check(i, j, -1, 0);
                    if(index == 3) check(i, j, 0, 1);
                    if(index == 4) check(i, j, 0, -1);
                }
            }
            if(map[i][j] == 2){
                int num1 = find(i, j, 1, 0) + find(i, j, -1, 0);
                int num2 = find(i, j, 0, 1) + find(i, j, 0, -1);
                if(num1 > num2){
                    check(i, j, 1, 0);
                    check(i, j, -1, 0);
                }
                else{
                    check(i, j, 0, 1);
                    check(i, j, 0, -1);
                }
            }
            if(map[i][j] == 3){
                // 남 동, 동 북, 북 서, 서 남
                int num1 = find(i, j, 1, 0) + find(i, j, 0, 1);
                int num2 = find(i, j, 0, 1) + find(i, j, -1, 0);
                int num3 = find(i, j, -1, 0) + find(i, j, 0, -1);
                int num4 = find(i, j, 0, -1) + find(i, j, 1, 0);
                int max = 0;
                int index = 0;
                if(max < num1) {
                    max = num1;
                    index = 1;
                }
                if(max < num2) {
                    max = num2;
                    index = 2;
                }
                if(max < num3) {
                    max = num3;
                    index = 3;
                }
                if(max < num4) {
                    max = num4;
                    index = 4;
                }
                if(max > 0){
                    if(index == 1) {
                        check(i, j, 1, 0);
                        check(i, j, 0, 1);
                    }
                    if(index == 2) {
                        check(i, j, 0, 1);
                        check(i, j, -1, 0);
                    }
                    if(index == 3) {
                        check(i, j, -1, 0);
                        check(i, j, 0, -1);
                    }
                    if(index == 4) {
                        check(i, j, 0, -1);
                        check(i, j, 1, 0);
                    }
                }
            }
            if(map[i][j] == 4){
                // 서, 남, 동, 북  (역으로)
                int num1 = find(i, j, 1, 0) + find(i, j, 0, 1) + find(i, j, -1, 0);
                int num2 = find(i, j, 0, 1) + find(i, j, -1, 0) + find(i, j, 0, -1);
                int num3 = find(i, j, -1, 0) + find(i, j, 0, -1) + find(i, j, 1, 0);
                int num4 = find(i, j, 0, -1) + find(i, j, 1, 0) + find(i, j, 0, 1);
                int max = 0;
                int index = 0;
                if(max < num1) {
                    max = num1;
                    index = 1;
                }
                if(max < num2) {
                    max = num2;
                    index = 2;
                }
                if(max < num3) {
                    max = num3;
                    index = 3;
                }
                if(max < num4) {
                    max = num4;
                    index = 4;
                }
                if(max > 0){
                    if(index == 1) {
                        check(i, j, 1, 0);
                        check(i, j, 0, 1);
                        check(i, j, -1, 0);
                    }
                    if(index == 2) {
                        check(i, j, 0, 1);
                        check(i, j, -1, 0);
                        check(i, j, 0, -1);
                    }
                    if(index == 3) {
                        check(i, j, -1, 0);
                        check(i, j, 0, -1);
                        check(i, j, 1, 0);
                    }
                    if(index == 4) {
                        check(i, j, 0, -1);
                        check(i, j, 1, 0);
                        check(i, j, 0, 1);
                    }
                }
            }
            if(map[i][j] == 5){
                check(i, j, 1, 0);
                check(i, j, -1, 0);
                check(i, j, 0, 1);
                check(i, j, 0, -1);
            }
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &map[i][j]);
        }
    }

    solve();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf(" %d ", map[i][j]);
            if(map[i][j] == 0) ans++;
        }
        printf("\n");
    }

    printf("%d", ans);
    return 0;
}