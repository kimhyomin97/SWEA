package °ýÈ£;
import java.io.*;

public class main {
	static int num;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		num = Integer.parseInt(br.readLine());
		
		for(int i=0; i<num; i++) {
			String str = br.readLine();
			boolean flag = true;
			int offset = 0;
			for(int j=0; j<str.length(); j++) {
				if(str.charAt(j) == '(') {
					offset++;
				}
				else {
					if(offset == 0) {
						flag = false;
						break;
					}
					offset--;
				}
			}
			if(flag && (offset == 0)) System.out.println("YES");
			else System.out.println("NO");
		}
	}
}
