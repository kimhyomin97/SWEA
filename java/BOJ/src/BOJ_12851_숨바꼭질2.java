// 7%에서 틀림 -> visit 처리를 해줘야 할듯
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class BOJ_12851_숨바꼭질2 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] line = br.readLine().split(" ");
		int n = Integer.parseInt(line[0]);
		int k = Integer.parseInt(line[1]);
		int[] list = new int[200002];
		Queue<Integer> arr = new LinkedList<>();
		arr.add(n);
		int second = 0;
		int cnt = 1;
		int min = 987654321;
		while(arr.size() != 0) {
			int size = arr.size();
			second++;
			for(int i=0; i<size; i++) {
				int now = arr.poll();
				if(now == k) {
					if(list[now] < min) {
						min = list[now];
						cnt = 1;
					}
					else if(list[now] == min) cnt++;
				}
				try {
					if(list[now+1] == 0 || list[now+1] >= second) {
						list[now+1] = second;
						arr.add(now+1);
					}
				}catch(Exception e) {}
				try {
					if(list[now-1] == 0 || list[now-1] >= second) {
						list[now-1] = second;
						arr.add(now-1);
					}	
				}catch(Exception e) {}
				try {
					if(list[now*2] == 0 || list[now*2] >= second) {
						list[now*2] = second;
						arr.add(now*2);
					}
				}catch(Exception e) {}
			}
		}
		list[n] = 0;
		System.out.println(cnt + " " + list[k]);
	}
}
