// 백준 2252 줄 세우기
// 메모리 초과 개선
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector <int> edge[32001];
bool visit[32001] = {false, };
int cnt[32001] = {0,};

int main(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        edge[a].push_back(b);
        cnt[b]++;
    }
    int len=0;
    int i=1;
    while(len < n){
        if(visit[i] == false && cnt[i] == 0){
            printf("%d ", i);
            visit[i] = true;
            len++;
            for(int j=0; j<edge[i].size(); j++){
                cnt[edge[i][j]]--;
            }
            i=0;
        }
        i++;
    }

    return 0;
}