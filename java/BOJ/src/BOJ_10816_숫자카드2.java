import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class BOJ_10816_숫자카드2 {
    public static void main(String[] args) throws Exception{
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
            int num = upperBound(target, list) - lowerBound(target, list);
            if(num > 0 || lowerBound(target, list) > 0) num++;
            sb.append(num).append(' ');
        }

        System.out.println(sb.toString());
    }

    public static int lowerBound(int num, int[] list){
        int start = 0;
        int end = list.length-1;
        int mid = (start + end) / 2;
        int target = 0;
        while(start <= end){
            mid = (start + end) / 2;
            if(num <= list[mid]){
                if(num == list[mid]) target = mid;
                end = mid-1;
            } else{
                start = mid+1;
            }
        }
        return target;
    }

    public static int upperBound(int num, int[] list){
        int start = 0;
        int end = list.length-1;
        int mid = (start + end) / 2;
        int target = 0;
        while(start <= end){
            mid = (start + end) / 2;
            if(num >= list[mid]){
                if(num == list[mid]) target = mid;
                start = mid+1;
            } else{
                end = mid-1;
            }
        }
        return target;
    }
}