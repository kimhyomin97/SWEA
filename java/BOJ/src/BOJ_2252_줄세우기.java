import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ_2252_줄세우기 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		ArrayList<Integer>[] edge = new ArrayList[n+1];
		int[] arr = new int[n+1];
		boolean[] check = new boolean[n+1];
		
		for(int i=0; i<=n; i++) {
			edge[i] = new ArrayList<>();
		}
		
		for(int i=0; i<m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			edge[a].add(b);
			arr[b]++;
		}
		
		for(int i=1; i<=n; i++) {
			int min = 9999999;
			int index = -1;
			for(int j=1; j<=n; j++) {
				if(arr[j] < min && check[j] == false) {
					min = arr[j];
					index = j;
				}
			}
			sb.append(index);
			sb.append(" ");
			check[index] = true;
			for(int j=0; j<edge[index].size(); j++) {
				arr[edge[index].get(j)]--;
			}
		}
		System.out.println(sb);
	}
}
