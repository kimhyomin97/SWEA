// 백준 17142 연구소3
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int map[50][50];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

struct pos{
    int row;
    int col;
};

vector <pos> virus;
vector <pos> select;
int cnt = 3;
int ans = 99999999;
int zero_cnt = 0;

bool check(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] != 1 && map[i][j] != cnt && map[i][j] != 2){
                return false;
            }
        }
    }
    return true;
}

void select_virus(int len, int index){
    if(len == m) {
        queue <pos> q;
        queue <pos> wait;
        for(int i=0; i<m; i++){
            map[select[i].row][select[i].col] = cnt;
            q.push(select[i]);
        }
        int sec = 0;
        int compare_cnt = 0;
        if(check()){
            ans = 0;
            return;
        }
        while(q.size()!=0 || wait.size() != 0){
            // if(sec >= ans) break;
            pos now = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nr = now.row + dr[i];
                int nc = now.col + dc[i];
                if(nr < 0 || nr >= n || nc < 0 || nc >= n || map[nr][nc] == 1 || map[nr][nc] == cnt) continue;
                else{
                    if(map[nr][nc] != 2) compare_cnt++;
                    map[nr][nc] = cnt;
                    // q.push({nr, nc});
                    wait.push({nr, nc});
                }
            }
            if(q.size() == 0 && wait.size() == 0) break;
            if(q.size() == 0){
                sec++;
                // if(check()) break;
                bool wait_flag = false;
                while(wait.size() != 0){
                    pos test = wait.front();
                    for(int i=0; i<4; i++){
                        int nr = test.row + dr[i];
                        int nc = test.col + dc[i];
                        if(nr < 0 || nr >= n || nc < 0 || nc >= n || map[nr][nc] == 1 || map[nr][nc] == cnt || map[nr][nc] == 2) continue;
                        else wait_flag = true;
                    }
                    q.push(wait.front());
                    wait.pop();
                }
                if(wait_flag == false && compare_cnt == zero_cnt) break;
                // if(wait_flag == false) {
                //     printf("%d %d \n", compare_cnt, zero_cnt);    
                //     break;
                // }
            }
        }
        if(check() == false){
            sec = 99999999;
        }
        if(sec < ans) ans = sec;
        cnt++;
        for(int i=0; i<virus.size(); i++){
            map[virus[i].row][virus[i].col] = 2;
        }
        return;
    }
    for(int i=index; i<virus.size(); i++){
        select.push_back(virus[i]);
        select_virus(len+1, i+1);
        select.pop_back();
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 2) virus.push_back({i, j});
            if(map[i][j] == 0) zero_cnt++;
        }
    }

    select_virus(0, 0);
    
    if(ans == 99999999){
        printf("-1");
    }
    else{
        printf("%d", ans);
    }

    return 0;
}