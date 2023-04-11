//https://school.programmers.co.kr/learn/courses/30/lessons/12979?language=cpp
//프로그래머스 기지국 설치 (단순구현) 
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int offset = w*2 + 1;
    
    answer += ceil((double)(stations[0]-w-1)/offset);
    
    for(int i=1; i<stations.size(); i++){
        int before = stations[i-1];
        int target = stations[i];
        int distance = (target-w) - (before+w) - 1;
        answer += ceil((double)distance/offset);
    }
    
    int last = n - (stations.back()+w);
    if(last > 0){
        answer += ceil((double)last/offset);
    }
    
    return answer;
}
