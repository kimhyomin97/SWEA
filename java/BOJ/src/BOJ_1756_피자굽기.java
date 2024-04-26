import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_1756_피자굽기 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int d = Integer.parseInt(st.nextToken()); // 1 <= d, n <= 300,000
        int n = Integer.parseInt(st.nextToken());
        int[] depth = new int[d]; // 1 <= depth[i], list[i] <= 1,000,000,000
        int[] offset = new int[d];
        int[] list = new int[n];

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<d; i++){
            depth[i] = Integer.parseInt(st.nextToken());
            if(i != 0) {
                offset[i] = Math.min(offset[i-1], depth[i]); // depth배열의 0 ~ index 까지 중 최소값
            } else {
                offset[i] = depth[i];
            }
        }
        st = new StringTokenizer(br.readLine());
        int now = d-1;
        for(int i=0; i<n; i++){
            list[i] = Integer.parseInt(st.nextToken());
        }

        for(int i=0; i<n; i++){
            if(now == 0) break;
            if(offset[now] >= list[i]){
                if(i==n-1) {
                    now++;
                    break;
                }
                now--;
            } else{
                now--;
                i--;
            }
        }
        System.out.println(now);
    }
}
