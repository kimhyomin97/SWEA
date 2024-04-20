import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_14888_연산자끼워넣기 {
    public static int max = Integer.MIN_VALUE;
    public static int min = Integer.MAX_VALUE;
    public static int n;
    public static int[] list;
    public static int[] oper;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        list = new int[n];
        oper = new int[4]; // + - * / 개수
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            list[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<4; i++){
            oper[i] = Integer.parseInt(st.nextToken());
        }
        dfs(0, list[0]);
        System.out.println(max);
        System.out.println(min);
    }
    public static void dfs(int cnt, int sum){
        if(cnt == n-1){
            if(sum > max){
                max = sum;
            }
            if(sum < min){
                min = sum;
            }
            return;
        }
        for(int i=0; i<4; i++){
            if(oper[i] != 0){
                oper[i]--;
                int temp = sum;
                if(i==0){
                    temp += list[cnt+1];
                }
                else if(i==1){
                    temp -= list[cnt+1];
                }
                else if(i==2){
                    temp *= list[cnt+1];
                }
                else if(i==3){
                    temp /= list[cnt+1];
                }
                dfs(cnt+1, temp);
                oper[i]++;
            }
        }
    }
}
