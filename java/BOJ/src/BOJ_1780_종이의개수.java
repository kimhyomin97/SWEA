import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_1780_종이의개수 {
	static int ans_minus = 0;
	static int ans_zero = 0;
	static int ans_one = 0;
	
	static void recur(int size, int row, int col, int[][] map) {
		int target = map[row][col];
		boolean flag = true;
		for(int i=0; i<size; i++) {
			for(int j=0; j<size; j++) {
				if(map[row+i][col+j] != target) {
					flag = false;
					break;
				}
			}
			if(flag == false) break;
		}
		if(flag == true) {
			if(target == -1) ans_minus++;
			if(target == 0) ans_zero++;
			if(target == 1) ans_one++;
			return;
		}
		for(int i=0; i<3; i++) {
			for(int j=0; j<3; j++) {
				int offset = size / 3;
				int nr = row + offset*i;
				int nc = col + offset*j;
				recur(offset, nr, nc, map);
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		
		int[][] map = new int[n][n];
		
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		recur(n, 0, 0, map);
		
		System.out.println(ans_minus);
		System.out.println(ans_zero);
		System.out.println(ans_one);
	}
}
