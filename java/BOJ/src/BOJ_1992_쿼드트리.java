import java.io.BufferedReader;
import java.io.InputStreamReader;


public class BOJ_1992_쿼드트리 {
	static String ans = "";
	static int[] dr = {0, 0, 1, 1};
	static int[] dc = {0, 1, 0, 1};
	static int n;
	static void recur(int size, int row, int col, int position, int[][] map) {
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
			ans += target;
		}
		if(flag == false) {
			ans += "(";
			for(int i=0; i<4; i++) {
				int offset = size/2;
				recur(offset, row+dr[i]*offset, col+dc[i]*offset, i, map);
			}
			ans += ")";
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		int[][] map = new int[n][n];
		for(int i=0; i<n; i++) {
			String line = br.readLine();
			for(int j=0; j<n; j++) {
				map[i][j] = line.charAt(j)-'0';
			}
		}
		// 4 사분면으로 나눠서 왼위 -> 오위 -> 왼아래 -> 오른 아래 순서로 탐색하는 방법
		recur(n, 0, 0, 0, map);
		System.out.println(ans);
	}
}
