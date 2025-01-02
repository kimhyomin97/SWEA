import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_1253_좋다 {

    static int ans = 0;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] list = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            list[i] = Integer.parseInt(st.nextToken());
        }

        if(n < 3) {
            System.out.println(0);
            return;
        }

        Arrays.sort(list);

        for(int i=0; i<n; i++){
            find(list, i, n);
        }
        System.out.println(ans);
    }

    public static void find(int[] list, int targetIndex, int size) {
        int target = list[targetIndex];
        int left = 0;
        int right = size - 1;

        while (left < right) {
            // targetIndex 제외
            if (left == targetIndex) {
                left++;
                continue;
            }
            if (right == targetIndex) {
                right--;
                continue;
            }

            int sum = list[left] + list[right];

            if (sum == target) {
                ans++;
                return; // 중복 방지: 첫 번째 발견 후 종료
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

}
