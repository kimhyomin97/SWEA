import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;

public class BOJ_15665_N과M11 {
	static int n, m;
	static ArrayList<Integer> list = new ArrayList<>();
	static StringBuilder sb = new StringBuilder();
	static void recur(int index, int[] ans) {
		if(index == m) {
			for(int i=0; i<m; i++) {
				sb.append(ans[i]).append(" ");
			}
			sb.append("\n");
			return;
		}
		for(int i=0; i<list.size(); i++) {
			ans[index] = list.get(i);
			recur(index+1, ans);
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		boolean[] check = new boolean[10001];
		
		for(int i=0; i<n; i++) {
			int num = Integer.parseInt(st.nextToken());
			if(check[num] == true) continue;
			else {
				check[num] = true;
				list.add(num);
			}
		}
		
		list.sort(Comparator.naturalOrder());
		
		int[] ans = new int[m];
		recur(0, ans);
		System.out.println(sb);
	}
}
