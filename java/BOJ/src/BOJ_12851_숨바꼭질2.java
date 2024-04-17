import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

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
		System.out.println(list[k] + "\n" + cnt);
	}
//	아래 코드도 정답, 시간 단축 648ms -> 192ms
	public static void sol() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken()); // 0 <= k <= 100000

		Queue<Integer> queue = new LinkedList<>();
		queue.add(n);
		int ans = 0;
		int ans_cnt = 0;
		int[] visit = new int[150001];
		if(n == k){
			System.out.println(0);
			System.out.println(1);
			return;
		}

		while(!queue.isEmpty()){
			int size = queue.size();
			ans++;
			for(int i=0; i<size; i++){
				int now = queue.poll();
				int nPosition;
				for(int j=0; j<3; j++){
					if(j==0){
						nPosition = now + 1;
					}
					else if(j==1){
						nPosition = now - 1;
					}
					else {
						nPosition = now * 2;
					}
					if(nPosition == k){
						ans_cnt++;
					}
					if(nPosition < 0 || nPosition >= 150001 || (visit[nPosition] < ans && visit[nPosition] > 0)){
						continue;
					}
					visit[nPosition] = ans;
					queue.add(nPosition);
				}
			}
			if(ans_cnt > 0) break;
		}
		System.out.println(ans);
		System.out.println(ans_cnt);
	}
}
