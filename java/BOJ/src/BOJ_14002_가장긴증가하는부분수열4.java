// DP
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ_14002_가장긴증가하는부분수열4 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int[] list = new int[n];
		int[] check = new int[n];
		ArrayList<Integer>[] arrayList = new ArrayList[n];

		st = new StringTokenizer(br.readLine());

		for(int i=0; i<n; i++) {
			list[i] = Integer.parseInt(st.nextToken());
			check[i] = 1;
			arrayList[i] = new ArrayList<>();
			arrayList[i].add(list[i]);
		}

		for(int i=n-1; i>=0; i--){
			int max_val = check[i];
			int max_idx = i;
			for(int j=i+1; j<n; j++){
				if(list[i] < list[j] && max_val <= check[j]){
					max_val = check[j];
					max_idx = j;
				}
			}
			if(max_idx != i){
				check[i] = max_val+1;
				arrayList[i] = (ArrayList<Integer>)arrayList[max_idx].clone();
				arrayList[i].add(list[i]);
			}
		}

		int ans_idx = 0;
		int ans_size = 0;
		for(int i=0; i<n; i++){
			if(arrayList[i].size() > ans_size){
				ans_idx = i;
				ans_size = arrayList[i].size();
			}
		}
		System.out.println(ans_size);
		for(int i=0; i<arrayList[ans_idx].size(); i++){
			System.out.print(arrayList[ans_idx].get(ans_size - i - 1)+" ");
		}
	}
}
