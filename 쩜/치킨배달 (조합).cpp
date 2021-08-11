// 백준 15686 치킨 배달
// 각 치킨집마다 집들과의 총 거리를 계산해서 작은 순서대로 남긴다
// 그리디한 방법으로는 풀리지 않는다
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int map[50][50];
struct pos {
    int row;
    int col;
};

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

vector <pos> house;
vector <pos> chicken;
int select[50];
bool visit[50] = {false,};

int ans = 99999999;

int cal(){
    int cost = 0;
    for(int i=0; i<house.size();i++){
        int min = 99999999;
        int len = 0;
        int index = 0;
        for(int j=0; j<m; j++){
            int index = select[j];
            if(house[i].row > chicken[index].row) len += house[i].row - chicken[index].row;
            else len += chicken[index].row - house[i].row;
            if(house[i].col > chicken[index].col) len += house[i].col - chicken[index].col;
            else len += chicken[index].col - house[i].col;
            if(min > len) {
                min = len;
            }
            len = 0;
        }
        cost += min;
    }
    return cost;
}

void solve(int len, int num = 0){
    if(len == m) {
        int cost = cal();
        if(ans > cost) ans = cost;
        return;
    }
    for(int i=num; i<chicken.size(); i++){
        if(visit[i] == false){
            select[len] = i;
            visit[i] = true;
            solve(len+1, i);
            visit[i] = false;
        }
    }
}

// 1 2 3 4 5 // 순열 테스트
// int test[5];
// bool visit[5] = {false, };
// void recur(int len){
//     if(len == 3) {
//         for(int i=0; i<3; i++){
//             printf("%d ", test[i]);
//         }
//         printf("\n");
//         return;
//     }
//     for(int i=0; i<5; i++){
//         if(visit[i] == false){
//             test[len] = i;
//             visit[i] = true;
//             recur(len+1);
//             visit[i] = false;
//         }
//     }
// }

int main(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1){
                house.push_back({i, j});
            }
            if(map[i][j] == 2){
                chicken.push_back({i, j});
            }
        }
    }

    solve(0, 0);
    // recur(0);

    printf("%d", ans);

    return 0;
}