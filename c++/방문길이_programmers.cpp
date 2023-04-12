// https://school.programmers.co.kr/learn/courses/30/lessons/49994
// 프로그래머스 방문 길이 (비트마스크, 단순구현) 
#include <string>
using namespace std;

int getReverse(int num){
    if(num == 1) return 3;
    if(num == 2) return 4;
    if(num == 3) return 1;
    if(num == 4) return 2;
}

int convert(char dir){
    if(dir=='U') return 1;
    if(dir=='R') return 2;
    if(dir=='D') return 3;
    if(dir=='L') return 4;
}

int solution(string dirs) {
    int answer = 0;
    int map[11][11];
    for(int i=0; i<11; i++){
        for(int j=0; j<11; j++){
            map[i][j] = 0;
        }
    }
    // 1 << 1 = 북, 1 << 2 = 동, 1 << 3 = 남, 1 << 4 = 서 : 비트마스킹으로 기록
    int row = 5, col = 5;
    for(int i=0; i<dirs.length(); i++){
        char dir = dirs[i];
        int num = convert(dir);
        int now = map[row][col];
        if(num == 1 && (col+1 > 10)) continue;
        if(num == 2 && (row+1 > 10)) continue;
        if(num == 3 && (col-1 < 0)) continue;
        if(num == 4 && (row-1 < 0)) continue;
        if(now & (1 << num)){
            // 이미 방문한 길
            if(num == 1) col += 1;
            if(num == 2) row += 1;
            if(num == 3) col -= 1;
            if(num == 4) row -= 1;
        }
        else {
            // 처음 걸어본 길
            answer++;
            // 걸어온 길 기록
            map[row][col] += (1 << num);
            if(num == 1) col += 1;
            if(num == 2) row += 1;
            if(num == 3) col -= 1;
            if(num == 4) row -= 1;
            // 걸어온 길 반대방향 기록
            int reverse = getReverse(num);
            map[row][col] += (1 << reverse);
        }
    }
    return answer;
}
