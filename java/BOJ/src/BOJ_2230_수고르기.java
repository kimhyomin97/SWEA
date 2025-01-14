import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_2230_수고르기 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()); // 1 <= N <= 100,000 (10만)
        int m = Integer.parseInt(st.nextToken()); // 1 <= M <= 2,000,000,000 (20억)
        int[] list = new int[n]; // 0 <= list[i] <= 1,000,000,000 (10억)

        for(int i=0; i<n; i++) {
            list[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(list);
        int left = 0;
        int right = 0;
        long ans = Long.MAX_VALUE;

        while(left <= right && left < n && right < n) {
            long num = list[right] - list[left];
            if(num >= m) {
                if(num < ans) {
                    ans = num;
                }
                left++;
            } else {
                right++;
            }
        }

        System.out.println(ans);
    }
}