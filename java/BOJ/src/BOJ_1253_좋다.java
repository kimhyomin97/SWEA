import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_1253_좋다 {

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

        boolean[] visit = new boolean[n];
        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(i == j) continue;

                int leftIndex = findLeftIndex(list, list[i] + list[j], n-1);
                int rightIndex = findRightIndex(list, list[i] + list[j], n-1);

                if(leftIndex != 2000000001 && rightIndex != 2000000001) {
                    for(int k=leftIndex; k<=rightIndex; k++){
                        if(k != i && k != j && visit[k] == false) {
                            ans++;
                            visit[k] = true;
                        }
                    }
                }
            }
        }

        System.out.println(ans);
    }

    public static int findLeftIndex(int[] list, int target, int size) {
        int left = 0;
        int right = size;
        int mid;

        int result = 2000000001;
        while(left <= right) {
            mid = (left + right) / 2;
            if(list[mid] == target) {
                result = mid;
                right = mid - 1;
            }
            if (list[mid] < target) {
                left = mid + 1;
            }
            if (list[mid] > target) {
                right = mid - 1;
            }
        }
        return result;
    }

    public static int findRightIndex(int[] list, int target, int size) {
        int left = 0;
        int right = size;
        int mid;

        int result = 2000000001;
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
