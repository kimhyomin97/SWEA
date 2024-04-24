import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BOJ_9935_문자열폭발_재시도 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String list = br.readLine();
        String target = br.readLine();
        StringBuilder sb = new StringBuilder();

        for(int i=0; i<list.length(); i++){
            char now = list.charAt(i);
            sb.append(now);
            if(now == target.charAt(target.length()-1) && sb.length() >= target.length()){
                boolean flag = true;
                for(int j=0; j<target.length(); j++){
                    if(sb.charAt(sb.length()-1-j) == target.charAt(target.length()-1-j)){
                        flag = true;
                    } else {
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    sb.delete(sb.length()-target.length(), sb.length());
                }
            }
        }
        if(sb.length() == 0){
            System.out.println("FRULA");
        } else {
            System.out.println(sb);
        }
    }
}
