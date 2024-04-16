import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_7569_토마토 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken()); // row
        int n = Integer.parseInt(st.nextToken()); // col
        int h = Integer.parseInt(st.nextToken()); // height

        int[][][] list = new int[h][n][m];
        Queue<info> queue = new LinkedList<>();
        int cnt = 0; // 남은 토마토의 개수

        for(int i=0; i<h; i++){
            for(int j=0; j<n; j++){
                st = new StringTokenizer(br.readLine());
                for(int k=0; k<m; k++){
                    list[i][j][k] = Integer.parseInt(st.nextToken());
                    if(list[i][j][k] == 1){
                        queue.add(new info(j, k, i));
                    }
                    else if(list[i][j][k] == 0){
                        cnt++;
                    }
                }
            }
        }

        int answer = 0;
        if(cnt == 0) {
            System.out.println(0);
            return;
        }

        int size = queue.size();
        int[] dr = {-1, 0, 1, 0, 0, 0}; // 북 동 남 서 위 아래
        int[] dc = {0, 1, 0, -1, 0, 0};
        int[] dh = {0, 0, 0, 0, 1, -1};

        while (!queue.isEmpty()) {
            size = queue.size();
            for (int i = 0; i < size; i++) {
                info now = queue.poll();
                for (int j = 0; j < 6; j++) {
                    int nr = now.row + dr[j];
                    int nc = now.col + dc[j];
                    int nh = now.height + dh[j];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && nh >= 0 && nh < h) {
                        if (list[nh][nr][nc] == 0) {
                            list[nh][nr][nc] = 1;
                            cnt--;
                            queue.add(new info(nr, nc, nh));
                        }
                    }
                }
            }
            answer++;
            // list에 값을 1씩 더해서 최대값을 구하는 방식으로도 정답 계산 가능
            // ex) list[nh][nr][nc] = list[now.height][now.row][now.col] + 1; -> answer = max(list...)
        }
        
        if(cnt != 0){
            System.out.println(-1);
        } else {
            System.out.println(answer-1);
        }
        return;
    }

    public static class info {
        int row;
        int col;
        int height;

        public info (int row, int col, int height){
            this.row = row;
            this.col = col;
            this.height = height;
        }
    }
}
