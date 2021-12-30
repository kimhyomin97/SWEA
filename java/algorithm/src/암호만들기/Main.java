package 암호만들기;
import java.io.*;
import java.util.*;

public class Main {
	private static int L, C;
	private static char[] arr;
	private static char[] ans; // 여기에 답을 넣을것이다.
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(br.readLine());
		L = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		ans = new char[L];
		arr = new char[C];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<C;i++) {
			String str = st.nextToken();
			arr[i] = str.charAt(0);
		}
		Arrays.sort(arr);
		// 여기까지가 입력?
		
		// 전략 - 완전탐색 -> 하나씩 손으로 써볼거다??
		recur(0,0);
		
	}
	public static void recur(int where, int from) {
		// where : 어디에 넣을 것인지??
		// from부터 보겠다는 뜻?
		
		// final condition
		if(where == L) {
//			String str = new String(ans);
//			System.out.println(ans);
			if(check()) {
				System.out.println(new String(ans));	
			}
			return;
		}
		for(int i=from; i<C; i++) {
			ans[where] = arr[i];
			recur(where + 1, i+1);
		}
	}
	
	public static boolean check() {
		int countMoeum = 0, countJaeum = 0;
		boolean[] isMoeum = new boolean[128]; // 아스키코드 128개 배열
		// 아스키코드 알파벳만 해도 된다
		isMoeum['a'] = true;
		isMoeum['e'] = true;
		isMoeum['i'] = true;
		isMoeum['o'] = true;
		isMoeum['u'] = true;
		
		for(int i=0;i<L;i++) { // 단어의 길이 == L
//			if(ans[i] == 'a' || ans[i] == 'o')
			if(isMoeum[ans[i]]) countMoeum++;
			else countJaeum++;
		}
//		if(countMoeum >= 1 && countJaeum >= 2) return true;
//		else return false; // 안써줘도 된다
		return countMoeum >= 1 && countJaeum >= 2;
	}
}



