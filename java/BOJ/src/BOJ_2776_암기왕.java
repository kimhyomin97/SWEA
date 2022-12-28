import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class BOJ_2776_암기왕 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		for(int testcase = 0; testcase<t; testcase++) {
			StringBuilder sb = new StringBuilder();
			
			int n = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			HashMap<Integer, Boolean> hash1 = new HashMap<>();
			for(int i=0; i<n; i++) hash1.put(Integer.parseInt(st.nextToken()), true);

			int m = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			for(int i=0; i<m; i++) {
				if(hash1.containsKey(Integer.parseInt(st.nextToken())) == true) sb.append("1\n");
				else sb.append("0\n");
			}
			System.out.print(sb);
		}
	}
}
