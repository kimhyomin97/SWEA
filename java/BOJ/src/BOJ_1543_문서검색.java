import java.io.BufferedReader;
import java.io.InputStreamReader;


public class BOJ_1543_문서검색 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		String target = br.readLine();
		
		int ans = 0;
		for(int i=0; i<line.length(); i++) {
			try {
				if(target.equals(line.substring(i, i+target.length()))) {
					ans++;
					i+=target.length()-1;
				}
			}catch(Exception e) {}
		}
		System.out.println(ans);
	}
}
