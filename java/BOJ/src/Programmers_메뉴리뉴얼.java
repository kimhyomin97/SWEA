// 프로그래머스 순열 구현문제
// https://school.programmers.co.kr/learn/courses/30/lessons/72411?language=java
import java.util.*;

class Solution {
    public HashMap <String, Integer> map = new HashMap<String, Integer>();
    public void recur(String str, String target, int index){
        if(index == str.length()) {
            if(target.length() >= 2){
                if(map.get(target) == null){
                    map.put(target, 1);
                }
                else{
                    map.put(target, map.get(target)+1);
                }
            }
            return;
        }
        recur(str, target, index+1);
        recur(str, target+str.charAt(index), index+1);
    }
    public String[] solution(String[] orders, int[] course) {
        String[] answer = {};
        String[] list = new String[orders.length];
        
        for(int i=0; i<orders.length; i++){
            char[] temp = orders[i].toCharArray();
            Arrays.sort(temp);
            list[i] = new String(temp);
            recur(new String(temp), "", 0);
        }
        
        for(String i : map.keySet()){
            System.out.println(i + " : " + map.get(i));
        }
        
        return answer;
    }
}