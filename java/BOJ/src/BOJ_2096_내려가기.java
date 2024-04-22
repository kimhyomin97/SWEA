import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_2096_내려가기 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine()); // 1 <= n <= 100,000
        int[][] list = new int[n][3];
        String[] temp = new String[3];
        for(int i=0; i<n; i++){
            temp = br.readLine().split(" ");
            list[i][0] = Integer.parseInt(temp[0]);
            list[i][1] = Integer.parseInt(temp[1]);
            list[i][2] = Integer.parseInt(temp[2]);
        }

        int[][] dp = new int[n][3];
        int[][] dp_max = new int[n][3];
        dp[0][0] = list[0][0];
        dp[0][1] = list[0][1];
        dp[0][2] = list[0][2];
        dp_max[0][0] = list[0][0];
        dp_max[0][1] = list[0][1];
        dp_max[0][2] = list[0][2];

        for(int i=1; i<n; i++){
            dp[i][0] = list[i][0] + Math.min(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = list[i][1] + Math.min(dp[i-1][0], Math.min(dp[i-1][1], dp[i-1][2]));
            dp[i][2] = list[i][2] + Math.min(dp[i-1][1], dp[i-1][2]);
            dp_max[i][0] = list[i][0] + Math.max(dp_max[i-1][0], dp_max[i-1][1]);
            dp_max[i][1] = list[i][1] + Math.max(dp_max[i-1][0], Math.max(dp_max[i-1][1], dp_max[i-1][2]));
            dp_max[i][2] = list[i][2] + Math.max(dp_max[i-1][1], dp_max[i-1][2]);
        }
        System.out.println(Math.max(dp_max[n-1][0], Math.max(dp_max[n-1][1], dp_max[n-1][2])) + " " + Math.min(dp[n-1][0], Math.min(dp[n-1][1], dp[n-1][2])));
    }
}
