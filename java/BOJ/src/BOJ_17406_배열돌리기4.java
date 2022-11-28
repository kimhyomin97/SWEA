import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ_17406_배열돌리기4 {
	static public int ans = 500001;
	static public class info{
		int r;
		int c;
		int s;
		public info(int r, int c, int s) {
			this.r = r;
			this.c = c;
			this.s = s;
		}
	}
	static public void getSum(int[][] arr) {
		int min_val = 500001;
		for(int i=0; i<arr.length; i++) {
			int tempSum = 0;
			for(int j=0; j<arr[0].length; j++) {
				tempSum += arr[i][j];
			}
			if(tempSum < min_val) min_val = tempSum;
		}
		if(min_val < ans) ans = min_val;
	}
	static public void rotate(int r1, int c1, int r2, int c2, int[][] arr) {
		// (r1, c1) -> (r2, c2) 시계방향으로 회전
		int temp = arr[r1][c1];
		for(int i=r1; i<r2; i++) {
			arr[i][c1] = arr[i+1][c1];
		}
		for(int j=c1; j<c2; j++) {
			arr[r2][j] = arr[r2][j+1];
		}
		for(int i=r2; i>r1; i--) {
			arr[i][c2] = arr[i-1][c2];
		}
		for(int j=c2; j>c1; j--) {
			arr[r1][j] = arr[r1][j-1];
		}
		arr[r1][c1+1] = temp;
	}
	static public void rotate_back(int r1, int c1, int r2, int c2, int[][] arr) {
		// (r1, c1) -> (r2, c2) 반시계방향으로 회전
		int temp = arr[r1][c1];
		for(int j=c1; j<c2; j++) {
			arr[r1][j] = arr[r1][j+1];
		}
		for(int i=r1; i<r2; i++) {
			arr[i][c2] = arr[i+1][c2];
		}
		for(int j=c2; j>c1; j--) {
			arr[r2][j] = arr[r2][j-1];
		}
		for(int i=r2; i>r1; i--) {
			arr[i][c1] = arr[i-1][c1];
		}
		arr[r1+1][c1] = temp;
	}
	
	static public void recur(int index, int[][] arr, ArrayList<info> list, boolean[] check) {
		if(index == list.size()) {
			getSum(arr);
			return;
		}
		
		for(int i=0; i<list.size(); i++) {
			if(check[i] == false) {				
				check[i] = true;
				int s = list.get(i).s;
				for(int j=1; j<=s; j++) {
					int r1 = list.get(i).r - j;
					int c1 = list.get(i).c - j;
					int r2 = list.get(i).r + j;
					int c2 = list.get(i).c + j;					
					rotate(r1, c1, r2, c2, arr);
				}
				recur(index+1, arr, list, check);
				for(int j=1; j<=s; j++) {
					int r1 = list.get(i).r - j;
					int c1 = list.get(i).c - j;
					int r2 = list.get(i).r + j;
					int c2 = list.get(i).c + j;		
					rotate_back(r1, c1, r2, c2, arr);
				}
				check[i] = false;
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		int[][] arr = new int[n][m];
		
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<m; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		ArrayList<info> list = new ArrayList<>();
		for(int i=0; i<k; i++) {
			st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());
			r--; c--;
			list.add(new info(r, c, s));
		}
		
		boolean[] check = new boolean[k];
		
		recur(0, arr, list, check);

		System.out.println(ans);
	}
}
