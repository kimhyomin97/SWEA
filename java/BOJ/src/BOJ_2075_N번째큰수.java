import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class BOJ_2075_N번째큰수 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Stack<Integer>[] stack = new Stack[n];
        for(int i=0; i<n; i++) stack[i] = new Stack<>();

        for(int i=0; i<n; i++){
            String[] str = br.readLine().split(" ");
            for(int j=0; j<n; j++){
                stack[j].push(Integer.parseInt(str[j]));
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            int index = 0;
            int max = Integer.MIN_VALUE;
            for(int j=0; j<n; j++){
                if(max < stack[j].peek()){
                    max = stack[j].peek();
                    index = j;
                }
            }
            ans = stack[index].pop();
        }

        System.out.println(ans);
    }
}
