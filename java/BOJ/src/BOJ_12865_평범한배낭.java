import java.io.*;
import java.util.*;

public class BOJ_12865_평범한배낭 {
	static public class info implements Comparable<info>{
		int value;
		int weight;
		public info(int value, int weight) {
			this.value = value;
			this.weight = weight;
		}
		@Override
		public int compareTo(info o) {
			// TODO Auto-generated method stub
			return this.value - o.value;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken()); // 물품의 개수
		int k = Integer.parseInt(st.nextToken()); // 최대 무게
		
//		ArrayList<info> list = new ArrayList<>();
		info[] list = new info[n];
		
		for(int i=0; i<n; i++) {
			int w, v; // w : weight, v : value
			st = new StringTokenizer(br.readLine());
			w = Integer.parseInt(st.nextToken());
			v = Integer.parseInt(st.nextToken());
//			list.add(new info(v, w));
//			list[i].weight = w;
//			list[i].value = v;
			list[i] = new info(v, w);
		}
//		Collections.sort(list); // value 기준 오름차순 정렬
//		Arrays.sort(list);
//		int[][] dp = new int[n+1][k+1];
		int[] dp = new int[k+1];
		
		for(int i=0; i<n; i++) {
			for(int j=k; j>=list[i].weight; j--) {
//				if(list[i].value > j) dp[i][j] = dp[i-1][j];
//				else dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-list[i].weight]+list[i].value);
				if(j-list[i].weight < 0) continue;
				dp[j] = Math.max(dp[j], dp[j-list[i].weight]+list[i].value);
			}
		}
		System.out.println(dp[k]);
	}
}
