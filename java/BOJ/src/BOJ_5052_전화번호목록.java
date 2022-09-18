import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class BOJ_5052_전화번호목록 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int testcase = Integer.parseInt(br.readLine());
		for(int T=0; T<testcase; T++) {
			int n = Integer.parseInt(br.readLine());
			HashMap<Long, Integer> map = new HashMap<>();
			boolean flag = true;
			for(int i=0; i<n; i++) {
				long number = Long.parseLong(br.readLine());
				long sum = 0;
				for(int j=9; j>=0; j--) {
					long offset = (number / (long)Math.pow(10, j))%10;
					sum = (sum*10)+offset;
					if(map.containsKey(sum) == true) {
						flag = false;
						break;
					}
				}
				map.put(number, 1);
				if(flag == false) break;
			}
			if(flag == true) System.out.println("YES");
			else System.out.println("NO");
		}
	}
}
