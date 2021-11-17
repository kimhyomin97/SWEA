import java.util.*;

public class Main {
	public static void main(String[] args){
		String str;
		int n;
		int sum = 0;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		str = sc.next();
		for(int i=0; i<str.length(); i++) {
			sum += str.charAt(i)-48;
		}
		System.out.println(sum);
	}
}