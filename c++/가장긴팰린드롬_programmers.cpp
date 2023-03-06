#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer=0;

    int len = s.size();
    char left, right;
    for(int i=0; i<len; i++){
        int cnt = 0;
        for(int j=0; j<len-i; j++){ // right 값이 left보다 왼쪽 값을 가르키지 않기 위해 len-i 까지 반복
            left = s[i+cnt]; // left 값은 앞뒤가 똑같을때만 한칸씩 오른쪽으로 이동
            right = s[len-j-1]; // right 값은 항상 한칸씩 왼쪽으로 이동
            if(left == right) cnt++;
            else{
                j-=cnt; // right값은 항상 한칸씩 이동하기 때문에, 카운팅 도중 오답을 발견할 시 초기화 필요 ex) abcbaa
                cnt = 0; // 오답 발견시 카운팅 초기화, left값을 다시 처음위치부터 비교할 수 있음
            }
        }
        if(cnt){ // flag값을 사용해도 되지만, 안쪽 for문에서 cnt가 초기화되지 않고 빠져나왔으면 팰린드롬 케이스
            if(answer < cnt) answer = cnt;
        }
    }

    return answer;
}
