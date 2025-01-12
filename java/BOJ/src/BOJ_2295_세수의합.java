import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BOJ_2295_세수의합 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        // 5 <= n <= 1000
        // n ^ 3 = 10억
        int[] list = new int[n];

        for(int i=0; i<n; i++){
            list[i] = Integer.parseInt(br.readLine());
        }

        int[] sumList = new int[n * n];
        int index = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                sumList[index++] = list[i] + list[j];
            }
        }

        Arrays.sort(list);
        Arrays.sort(sumList);

        int ans = -1;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int result = find(sumList, list[j] - list[i], index-1);
                result += list[i];
                if(result != Integer.MIN_VALUE && result > ans) ans = result;
            }
        }
        // x + y + z = k
        // x + y = k - z
        System.out.println(ans);

    }

    public static int find(int[] list, int target, int size) {
        int left = 0;
        int right = size;
        int mid;
        int index = Integer.MIN_VALUE;

        while(left <= right) {
            mid = (left + right) / 2;
            if(list[mid] == target) {
                return target;
            }
            if(list[mid] > target) {
                right = mid - 1;
            }
            if(list[mid] < target) {
                left = mid + 1;
            }
        }

        return index;
    }
}
