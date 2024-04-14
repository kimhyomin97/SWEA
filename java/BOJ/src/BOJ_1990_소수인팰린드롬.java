import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_1990_소수인팰린드롬 {
    public static void main(String[] args) throws Exception {
        int a, b;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken()); // 5 <= a < b <= 100,000,000
        // TODO : 소수이면서 동시에 팰린드롬인 수 모두 출력
        // 팰린드롬 : 앞으로 읽으나 뒤로 읽으나 같은 수

        String test = "ab";
        for(int i=a; i<=b; i++){
            if(isPalin(i)){
                if(isPrime(i)) {
                    System.out.println(i);
                }
            }
        }

        System.out.println(-1);
    }

    public static boolean isPalin(int num){
        String str = String.valueOf(num);
        int len = str.length();
        for(int i=0; i<len/2; i++){
            if(str.charAt(i) != str.charAt(len-1-i))
                return false;
        }
        return true;
    }

    public static boolean isPrime(int num){
        for(int i=2; i<= Math.sqrt(num); i++){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }
}
