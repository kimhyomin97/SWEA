import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BOJ_9935_문자열폭발 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String str = br.readLine();
		String bomb = br.readLine();
		int b_size = bomb.length();
		
		while(true) {
			if(str.contains(bomb)) {
				str = str.replace(bomb, "");
			}
			else {
				break;
			}
		}
		// string replace는 내부적으로 많은 가비지 콜렉션이 발생한다
		// 따라서 이 코드는 메모리 초과가 발생하게 된다
		if(str == "") System.out.println("FRULA");
		else System.out.println(str);
	}
}
