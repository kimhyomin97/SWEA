import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BOJ_7490_0만들기 {
	static StringBuilder sb = new StringBuilder();
	
	static void recur(int now, int len, int sum, String temp, int before) {
		if(now > len) {
			if(sum == 0) sb.append(temp+"\n");
//			System.out.println(temp + " : " + sum);
			return;
		}
		recur(now+1, len, sum+now, temp+"+"+Integer.toString(now), now); // +
		recur(now+1, len, sum-now, temp+"-"+Integer.toString(now), now*-1); // -
		int calc = before*10;
		if(calc > 0) calc += now;
		else calc -= now;
		recur(now+1, len, sum-before+calc, temp+" "+Integer.toString(now), calc); // " "
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		for(int i=0; i<n; i++) {
			int num = Integer.parseInt(br.readLine());
			String temp = "1";
			recur(2, num, 1, temp, 1);
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
