import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class BOJ_2668_숫자고르기 {
    public static int ans;
    public static ArrayList<Integer> ans_list = new ArrayList<>();
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] list = new int[n];
        boolean[] visit = new boolean[n];

        for(int i=0; i<n; i++){
            list[i] = Integer.parseInt(br.readLine());
            visit[i] = false;
        }
        dfs(0,  n, list, visit);

        System.out.println(ans);
        for(int i=0; i<ans_list.size(); i++){
            System.out.println(ans_list.get(i));
        }
    }

    public static void dfs(int now, int n, int[] list, boolean[] visit){
        // TODO : 메모리 초과 해결필요 -> 2^100 - 1 가지의 경우의수가 있기 때문에
        ArrayList<Integer> temp1 = new ArrayList<>();
        ArrayList<Integer> temp2 = new ArrayList<>();
        for(int i=0; i<n; i++){
            if(visit[i] == true){
                temp1.add(i+1);
                temp2.add(list[i]);
            }
        }
        Collections.sort(temp1);
        Collections.sort(temp2);
        boolean flag = true;
        int size = temp1.size();
        for(int i=0; i<size; i++){
            if(temp1.get(i) != temp2.get(i)) {
                flag = false;
                break;
            }
        }
        if(flag == true && size > ans){
            ans = size;
            ans_list = new ArrayList<>(temp1);
        }

        for(int i=now; i<n; i++){
            if(visit[i] == false){
                visit[i] = true;
                dfs(now+1, n, list, visit);
                visit[i] = false;
            }
        }
    }
}
