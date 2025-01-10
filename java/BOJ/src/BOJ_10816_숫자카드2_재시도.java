import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_10816_숫자카드2_재시도 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());

        int[] list = new int[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            list[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(list);

        int m = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());

        StringBuilder sb = new StringBuilder();

        for(int i=0; i<m; i++){
            int target = Integer.parseInt(st.nextToken());
            int left = findLeftIndex(list, target);
            int right = findRightIndex(list, target);
            if(left == 10000001 && right == 10000001) {
                sb.append("0 ");
            } else {
                sb.append((right-left+1)+" ");
            }
        }
        System.out.println(sb);
    }

    public static int findLeftIndex(int[] list, int target) {
        int left = 0;
        int right = list.length-1;
        int mid;

        int result = 10000001;
        while(left <= right) {
            mid = (left + right) / 2;
            if(list[mid] == target) {
                result = mid;
                right = mid - 1;
            }
            if(list[mid] < target) {
                left = mid + 1;
            }
            if(list[mid] > target) {
                right = mid - 1;
            }
        }

        return result;
    }

    public static int findRightIndex(int[] list, int target) {
        int left = 0;
        int right = list.length-1;
        int mid;

        int result = 10000001;
        while(left <= right) {
            mid = (left + right) / 2;
            if(list[mid] == target) {
                result = mid;
                left = mid + 1;
            }
            if(list[mid] < target) {
                left = mid + 1;
            }
            if(list[mid] > target) {
                right = mid - 1;
            }
        }

        return result;
    }
}