import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BOJ_9257_1의개수세기 {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        long left = Long.parseLong(input[0]); // 1 <= left, right <= 1,000,000,000,000,000 (10^16)
        long right = Long.parseLong(input[1]);

        long num = 0;
        for(long i=left; i<=right; i++){
            num += countNumber(i);
        }
        System.out.println(num);
    }
    public static int countNumber(long num){
        long offset = (long)Math.pow(2, 52); //  4,503,599,627,370,496
        int cnt = 0;
        while(offset >= 1 && num != 0){
            if(num >= offset){
                cnt++;
                num -= offset;
            }
            offset /= 2;
        }
        return cnt;
    }
}
