import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BOJ_1256_사전 {
    public static int n;
    public static int m;
    public static int k;
    public static int size;
    public static String ans = "";
    static int[][] dp;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]); // 1 <= n, m <= 100
        m = Integer.parseInt(input[1]);
        k = Integer.parseInt(input[2]); // 1 <= k <= 1,000,000,000 (10억)

        dp = new int[n + m + 1][n + m + 1];

        size = comb(n + m, m);
        if (size < k) {
            System.out.println(-1);
            return;
        }
        dfs();
        System.out.println(ans);
    }

    public static int comb(int n, int r){
        if(n == r || r == 0) return dp[n][r] = 1;
        if(dp[n][r] > 0) return dp[n][r];
        return dp[n][r] = Math.min(comb(n-1, r-1) + comb(n-1, r), 1000000001);
    }

    public static void dfs(){
        int offset = 0;
        if(n > 0 && m > 0){
//            offset = fact(n+m-1) / (fact(n-1) * fact(m)); // factorial 사용시 n, m의 크기가 17을 넘어가면 overflow 발생 (n, m <= 100)
            offset = comb(n+m-1, n-1);
            // 문자열의 총 경우의수 = a로 시작하는 경우의수 + z로 시작하는 경우의수
            // a로 시작하는 문자열의 수보다 k값이 크면, z로 시작한다고 판단
            // comb(n+m-1, n-1) = a의 개수를 하나 뺀 상황에서의 문자열의 총 개수 -> a로 시작하는 경우의 수
            if(k > offset){
                m--;
                ans += "z";
                k -= offset;
            } else {
                n--;
                ans += "a";
            }
            dfs();
        }
        else if(n > 0){
            n--;
            ans += "a";
            dfs();
        }
        else if(m > 0){
            m--;
            ans += "z";
            dfs();
        }
        else {
            return;
        }
    }
}