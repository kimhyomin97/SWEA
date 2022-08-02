import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_2283_구간자르기 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		int[] sum = new int[1000001];
		long total = 0;
		
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			for(int j=a; j<b; j++) {
				sum[j]++;
			}
			total += b-a;
		}
		long offset = sum[0];
		int left = 0;
		int right = 0;
		boolean flag = true;
		while(offset != k) {
			try {
				if(offset < k) {
					right++;
					offset += sum[right];
				}
				else if(offset > k) {
					offset -= sum[left];
					left++;
				}
			} catch (Exception e) {
				flag = false;
				break;
			}
		}
		if(flag) {
			right++;
			System.out.println(left+" "+right);
		}
		else {
			System.out.println("0 0");
		}
	}
}
