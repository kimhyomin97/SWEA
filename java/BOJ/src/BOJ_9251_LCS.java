import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BOJ_9251_LCS {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str1 = br.readLine();
        String str2 = br.readLine();
        int len1 = str1.length();
        int len2 = str2.length();
        int[][] dp = new int[len2+1][len1+1];

        for(int i=0; i<=len1; i++) {
            dp[0][i] = 0;
        }
        for(int i=0; i<=len2; i++){
            dp[i][0] = 0;
        }

        int ans = 0;

        for(int i=1; i<=len2; i++){
            char target = str2.charAt(i-1);
            for(int j=1; j<=len1; j++){
                char temp = str1.charAt(j-1);
                if(target == temp){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    // max 값 저장
                    if(dp[i-1][j] > dp[i][j-1]){
                        dp[i][j] = dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }

        System.out.println(dp[len2][len1]);
    }
}
