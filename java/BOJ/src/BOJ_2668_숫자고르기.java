import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class BOJ_2668_숫자고르기 {

    public static int n = 0;
    public static int max_value = 0;
    public static boolean[] ans_visit;
    public static ArrayList<Integer> ans = new ArrayList();
    public static ArrayList<Integer> temp = new ArrayList();
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        int[] list = new int[n+1];
        boolean[] visit = new boolean[n+1];
        ans_visit = new boolean[n+1];

        for(int i=1; i<=n; i++){
            list[i] = Integer.parseInt(br.readLine());
            visit[i] = false;
        }



        for(int i=1; i<=n; i++){
            if(ans_visit[i] == false) dfs(list, visit, i, i);
            temp.clear();
        }

        System.out.println(max_value);
        Collections.sort(ans);
        for(int i=0; i<ans.size(); i++){
            System.out.println(ans.get(i));
        }
    }

    public static void dfs(int[] list, boolean[] visit, int num, int index){
        if(visit[num] == true){
            if(num == index){
                max_value += temp.size();
                for(int i=0; i<temp.size(); i++){
                    ans.add(temp.get(i));
                    ans_visit[temp.get(i)] = true;
                }
                temp.clear();
            }
            return;
        }

        visit[num] = true;
        temp.add(num);
        dfs(list, visit, list[num], index);
        visit[num] = false;
    }

}
