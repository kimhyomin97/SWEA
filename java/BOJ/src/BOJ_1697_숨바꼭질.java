import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class BOJ_1697_숨바꼭질 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] line = br.readLine().split(" ");
		int n = Integer.parseInt(line[0]);
		int k = Integer.parseInt(line[1]);
		int[] list = new int[200002];
		Queue<Integer> arr = new LinkedList<>();
		arr.add(n);
		int second = 0;
		while(arr.size() != 0) {
			int size = arr.size();
			second++;
			for(int i=0; i<size; i++) {
				int now = arr.poll();
				try {
					if(list[now+1] == 0 || list[now+1] > second) {
						list[now+1] = second;
						arr.add(now+1);
					}
				}catch(Exception e) {}
				try {
					if(list[now-1] == 0 || list[now-1] > second) {
						list[now-1] = second;
						arr.add(now-1);
					}	
				}catch(Exception e) {}
				try {
					if(list[now*2] == 0 || list[now*2] > second) {
						list[now*2] = second;
						arr.add(now*2);
					}
				}catch(Exception e) {}
			}
		}
		list[n] = 0;
		System.out.println(list[k]);
	}
}
