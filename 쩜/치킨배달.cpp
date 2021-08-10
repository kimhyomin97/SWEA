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
    int cost = 0;
    int row;
    int col;
};

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

vector <pos> house;
vector <pos> chicken;

int ans = 0;

bool operator < (pos a, pos b){
    return a.cost > b.cost;
}

void cal(){
    for(int i=0; i<house.size(); i++){
        pos temp = house[i];
        queue <pos> q;
        q.push(temp);
        bool flag = false;
        bool visit[50][50] = {false,};
        visit[temp.row][temp.col] = true;
        while(q.size()!=0){
            pos now = q.front();
            q.pop();
            int nr, nc;
            for(int i=0; i<4; i++){
                nr = now.row + dr[i];
                nc = now.col + dc[i];
                if(nr < 0 || nr >= n || nc < 0 || nc >= n || visit[nr][nc] == true) continue;
                else{
                    visit[nr][nc] = true;
                    // if(map[nr][nc] == 2){
                    if(map[nr][nc] == 3){
                        flag = true;
                        break;
                    }
                    q.push({0, nr, nc});
                }
            }
            if(flag == true){
                if(temp.row > nr) ans += temp.row - nr;
                else ans += nr - temp.row;
                if(temp.col > nc) ans += temp.col - nc;
                else ans += nc - temp.col;
                break;
            }
        }
    }
}

void solve(){
    priority_queue <pos> pq;
    for(int i=0; i<chicken.size(); i++){
        pos now = chicken[i];
        for(int j=0; j<house.size(); j++){
            if(now.row > house[j].row) now.cost += now.row-house[j].row;
            else now.cost += house[j].row - now.row;
            if(now.col > house[j].col) now.cost += now.col-house[j].col;
            else now.cost += house[j].col - now.col;
        }
        pq.push(now);
    }
    // while(pq.size() != 0){
    for(int i=0; i<m; i++){
        pos now = pq.top();
        pq.pop();
        map[now.row][now.col] = 3;
        // printf("%d %d %d \n", now.cost, now.row, now.col);
    }
    cal();
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1){
                house.push_back({0, i, j});
            }
            if(map[i][j] == 2){
                chicken.push_back({0, i, j});
            }
        }
    }

    // cal();
    solve();

    printf("%d", ans);

    return 0;
}