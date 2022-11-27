// 재귀로 풀었을 때 시간초과 -> 유니온 파인드로 풀어야 될 듯 하다
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;

public class BOJ_4195_친구네트워크 {
	static public int ans;
	static public void recur(String now, HashMap<String, ArrayList<String>> hashmap, HashMap<String, Boolean> check) {
		check.put(now, true);
		ArrayList<String> temp = hashmap.get(now);
		for(int i=0; i<temp.size(); i++) {
			if(check.get(temp.get(i)) == null) {
				ans++;
				recur(temp.get(i), hashmap, check);
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testcase = Integer.parseInt(br.readLine());
		for(int TC=1; TC<=testcase; TC++) {
			int num = Integer.parseInt(br.readLine());
			HashMap<String, ArrayList<String>> hashmap = new HashMap<>();
			for(int i=0; i<num; i++) {
				HashMap<String, Boolean> check = new HashMap<>();
				ans = 1;
				String[] line = br.readLine().split(" ");
				// 추가하는 부분
				if(hashmap.get(line[0]) == null) {
					ArrayList<String> temp = new ArrayList<>();
					temp.add(line[1]);
					hashmap.put(line[0], temp);
				}
				else {
					hashmap.get(line[0]).add(line[1]);
				}
				if(hashmap.get(line[1]) == null) {
					ArrayList<String> temp = new ArrayList<>();
					temp.add(line[0]);
					hashmap.put(line[1], temp);
				}
				else {
					hashmap.get(line[1]).add(line[0]);
				}
				// 계산하는 부분
				recur(line[0], hashmap, check);
				System.out.println(ans);
				// 초기화 하는 부분
//				recur(line[0], hashmap, check, false);
			}
		}
	}
}
