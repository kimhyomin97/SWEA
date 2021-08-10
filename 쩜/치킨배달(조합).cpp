// 백준 15686 치킨배달 
// 조합으로 하나하나 계산해보는 방법
#include <cstdio>
#include <vector>
using namespace std;

int n, m;
int map[50][50];

struct pos{
    int row;
    int col;
};

vector <pos> house;
vector <pos> chicken;

int main(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1){
                house.push_back({i,j});
            }
            if(map[i][j] == 2){
                house.push_back({i,j});
            }
        }
    }

    

    return 0;
}