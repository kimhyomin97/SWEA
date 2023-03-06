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
        for(int j=0; j<len-i; j++){
            left = s[i+cnt];
            right = s[len-j-1];
            if(left == right) cnt++;
            else{
                j-=cnt;
                cnt = 0;
            }
        }
        if(cnt){
            if(answer < cnt) answer = cnt;
        }
    }

    return answer;
}
