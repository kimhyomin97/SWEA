package 게임;
import java.io.*;
import java.util.*;

public class 게임 {
//public class Main{
	private static long X, Y, Z;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(br.readLine());
		X = Long.parseLong(st.nextToken());
		Y = Long.parseLong(st.nextToken());
		
		if(X == Y) {
			System.out.println(-1);
			return;
		}
		
		Z = Y*100/X;
		
		if(Z == 100 || Z == 99) {
			System.out.println(-1);
			return;
		}
		
		long bottom = 1, top = 1000000000, mid;
		long answer = 1000000000;
		while(bottom <= top) {
			mid = (bottom + top) / 2;
			long nextZ = (Y + mid) * 100 / (X+mid);
			if(Z < nextZ) {
				if(mid < answer) {
					answer = mid;
				}
				top = mid - 1;
			}
			else {
				bottom = mid + 1;
			}
		}
		System.out.println(answer);
	}

}
