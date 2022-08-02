import java.io.BufferedReader;

public class BOJ_1644_소수의연속합 {
	static int ans = 0;
	static int size = 0;
	static int num;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new java.io.InputStreamReader(System.in));
		num = Integer.parseInt(br.readLine());
		
		boolean[] list = new boolean[num+1];
		
		for(int i=2; i<=num; i++) {
			if(!list[i]) {
				for(int j=i+i; j<=num; j+=i) {
					list[j] = true;
				}
				size++;
			}
		}
		int[] primes = new int[size+1];
		int offset = 0;
		for(int i=2; i<=num; i++) {
			if(!list[i]) {
				primes[offset++] = i;
			}
		}
		
		int left = 0, right = 1;
		int sum = primes[0];
		while(right <= size && left < right) {
			if(sum <= num) {
				if(sum == num) ans++;
				sum += primes[right];
				right++;
			}
			else if(sum > num) {
				sum -= primes[left];
				left++;
			}
		}
		
		System.out.println(ans);
	}
}
