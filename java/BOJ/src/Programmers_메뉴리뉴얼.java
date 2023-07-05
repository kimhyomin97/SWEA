// 프로그래머스 순열 구현문제
// https://school.programmers.co.kr/learn/courses/30/lessons/72411?language=java
import java.util.*;

class Programmers_메뉴리뉴얼 {
    public HashMap <String, Integer> map = new HashMap<String, Integer>();
    public void recur(String str, String target, int index, int[] course){
        if(index == str.length()) {
            int targetLen = target.length();
            boolean flag = false;
            for(int i=0; i<course.length; i++){
                if(course[i] == targetLen) {
                    flag = true;
                    break;
                }
            }
            if(flag){
                if(map.get(target) == null){
                    map.put(target, 1);
                }
                else{
                    map.put(target, map.get(target)+1);
                }
            }
            return;
        }
        recur(str, target, index+1, course);
        recur(str, target+str.charAt(index), index+1, course);
    }
    public String[] solution(String[] orders, int[] course) {
        // String[] answer = {};
        ArrayList<String> answer = new ArrayList<>();
        
        for(int i=0; i<orders.length; i++){
            char[] temp = orders[i].toCharArray();
            Arrays.sort(temp);
            recur(new String(temp), "", 0, course);
        }
        
        for(int i=0; i<course.length; i++){
            ArrayList<String> tempAnswer = new ArrayList<>();
            int maxLen = 0;
            for(String key : map.keySet()){
                if(key.length() == course[i]){
                    if(map.get(key) >= maxLen){
                        if(map.get(key) > maxLen) tempAnswer.clear();
                        if(map.get(key) >= 2){
                            tempAnswer.add(key);
                            maxLen = map.get(key);
                        }
                    }
                }
            }
            answer.addAll(tempAnswer);
        }
        String[] arrayAnswer = answer.toArray(new String[0]);
        Arrays.sort(arrayAnswer);
        return arrayAnswer;
    }
}