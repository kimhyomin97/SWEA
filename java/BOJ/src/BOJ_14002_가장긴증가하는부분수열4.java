import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class BOJ_14002_가장긴증가하는부분수열4 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int[] list = new int[n];
		int cnt = 0;
		List<Integer> ans = new ArrayList<>();
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<n; i++) {
			list[i] = Integer.parseInt(st.nextToken());
			
		}
		
	}
}
