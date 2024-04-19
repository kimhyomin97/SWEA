import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_10282_해킹 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int testcase = Integer.parseInt(st.nextToken());
        for(int t = 0; t<testcase; t++){
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken()); // 1 <= n <= 10,000
            int d = Integer.parseInt(st.nextToken()); // 1 <= d <= 100,000
            int c = Integer.parseInt(st.nextToken()); // 1 <= c <= n
            int cnt = 0;
            int time = 0;
            ArrayList<info>[] list = new ArrayList[n+1];
            for(int i=0; i<n+1; i++) list[i] = new ArrayList<>();
            int[] visit = new int[n+1];
            Queue<Integer> q = new LinkedList<>();
            q.add(c);
            visit[c] = 1;
            for(int i=0; i<d; i++){
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken()); // 1 <= a, b <= n
                int b = Integer.parseInt(st.nextToken()); // a != b
                int s = Integer.parseInt(st.nextToken()); // 0 <= s <= 1,000
                // a 가 b 의존 -> b가 감염되면 s초 이후 a도 감염
                list[b].add(new info(b, a, s));
            }
            while(!q.isEmpty()){
                int position = q.poll();
                int size = list[position].size();
                for(int i=0; i<size; i++){
                    info now = list[position].get(i);
                    if(visit[now.dest] == 0 || (visit[now.dest] > visit[now.start] + now.cost)){
                        visit[now.dest] = visit[now.start] + now.cost;
                        q.add(now.dest);
                    }
                }
            }
            for(int i=1; i<=n; i++){
                if(visit[i] != 0){
                    cnt++;
                }
                if(time < visit[i]){
                    time = visit[i];
                }
            }
            System.out.println(cnt + " " + (time-1));
        }
    }
    public static class info{
        int start;
        int dest;
        int cost;
        public info(int start, int dest, int cost){
            this.start = start;
            this.dest = dest;
            this.cost = cost;
        }
    }
}
