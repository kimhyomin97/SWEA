// 프로그래머스 우선순위큐 구현문제
// https://school.programmers.co.kr/learn/courses/30/lessons/42628
import java.util.*;

class Programmers_이중우선순위큐 {
    public class infoMax implements Comparable<infoMax> {
        int value;
        int index;
        public infoMax(int value, int index){
            this.value = value;
            this.index = index;
        }
        @Override
        public int compareTo(infoMax o){
            return o.value - this.value;
        }
    }
    public class infoMin implements Comparable<infoMin> {
        int value;
        int index;
        public infoMin(int value, int index){
            this.value = value;
            this.index = index;
        }
        @Override
        public int compareTo(infoMin o){
            return this.value - o.value;
        }
    }

    public int[] solution(String[] operations) {
        PriorityQueue<infoMin> min_pq = new PriorityQueue<>();
        PriorityQueue<infoMax> max_pq = new PriorityQueue<>();
        HashMap<Integer, Boolean> map = new HashMap<>();

        int offset = 0;
        for(int i=0; i<operations.length; i++){
            String[] temp = operations[i].split(" ");
            if("I".equals(temp[0])){
                int value = 0;
                if("-".equals(temp[1].charAt(0))){
                    value = Integer.parseInt(temp[1].substring(1));
                }
                else {
                    value = Integer.parseInt(temp[1]);
                }
                min_pq.add(new infoMin(value, offset));
                max_pq.add(new infoMax(value, offset));
                map.put(offset, true);
                offset++;
            }
            else if("D".equals(temp[0])){
                if("1".equals(temp[1])){
                    while(true){
                        if(max_pq.isEmpty()) break;
                        infoMax tempInfo = max_pq.poll();
                        Boolean flag = map.get(tempInfo.index);
                        if(flag == true){
                            map.put(tempInfo.index, false);
                            break;
                        }
                    }
                }
                else{
                    while(true){
                        if(min_pq.isEmpty()) break;
                        infoMin tempInfo = min_pq.poll();
                        Boolean flag = map.get(tempInfo.index);
                        if(flag == true){
                            map.put(tempInfo.index, false);
                            break;
                        }
                    }
                }
            }
        }
        int[] answer = {0, 0};
        while(true){
            if(max_pq.isEmpty()) break;
            infoMax tempInfo = max_pq.poll();
            Boolean flag = map.get(tempInfo.index);
            if(flag == true){
                answer[0] = tempInfo.value;
                // map.put(tempInfo.index, false);
                break;
            }
        }
        while(true){
            if(min_pq.isEmpty()) break;
            infoMin tempInfo = min_pq.poll();
            Boolean flag = map.get(tempInfo.index);
            if(flag == true){
                answer[1] = tempInfo.value;
                // map.put(tempInfo.index, false);
                break;
            }
        }

        return answer;
    }
}