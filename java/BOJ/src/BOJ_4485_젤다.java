import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_4485_젤다 {
	static public class info{
		int row;
		int col;
		public info(int row, int col) {
			this.row = row;
			this.col = col;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n = 1;
		int cnt = 1;
		while(true) {
			n = Integer.parseInt(br.readLine());
			if(n == 0) break;
			int[][] map = new int[n][n];
			int[][] cost = new int[n][n];
			for(int i=0; i<n; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0; j<n; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
					cost[i][j] = 987654321;
				}
			}
			Queue<info> q = new LinkedList<>();
			q.add(new info(0, 0));
			cost[0][0] = map[0][0];
			int[] dr = {1, -1, 0, 0};
			int[] dc = {0, 0, 1, -1};
			while(q.size() != 0) {
				info now = q.poll();
				for(int i=0; i<4; i++) {
					int nr = now.row + dr[i];
					int nc = now.col + dc[i];
					try {
						if(cost[nr][nc] > cost[now.row][now.col]+map[nr][nc]) {
							cost[nr][nc] = cost[now.row][now.col]+map[nr][nc];
							q.add(new info(nr, nc));
						}
					}catch(Exception e) {};
				}
			}
			
			System.out.printf("Problem %d: %d\n", cnt++, cost[n-1][n-1]);
		}
	}
}
