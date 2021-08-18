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

void select_virus(int len, int index){
    if(len == m) {
        queue <pos> q;
        queue <pos> wait;
        for(int i=0; i<m; i++){
            map[select[i].row][select[i].col] = cnt;
            q.push(select[i]);
        }
        int sec = 0;
        while(q.size()!=0 && wait.size() != 0){
            pos now = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nr = now.row + dr[i];
                int nc = now.col + dc[i];
                if(nr < 0 || nr >= n || nc < 0 || nc >= n || map[nr][nc] == 1 || map[nr][nc] == cnt) continue;
                else{
                    map[nr][nc] = cnt;
                    // q.push({nr, nc});
                    wait.push({nr, nc});
                }
            }
            if(q.size() == 0){
                sec++;
                while(wait.size() != 0){
                    q.push(wait.front());
                    wait.pop();
                }
            }
        }
        bool flag = true;
        printf("\n");
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // if(map[i][j] != 1 && map[i][j] != cnt && map[i][j] != 2){

                //     flag = false;
                //     break;
                // }
                printf("%d ", map[i][j]);
                // 바이러스가 비활성인 상태는 무엇인가?
            }
            printf("\n");
            if(flag == false) break;
        }
        if(flag == false){
            sec = 99999999;
        }
        if(sec < ans) ans = sec;
        cnt++;
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