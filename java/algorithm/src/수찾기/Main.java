package ¼öÃ£±â;
import java.io.*;
import java.util.*;

public class Main {
	private static int N;
	private static int M;
	private static Map<Integer, Integer> map = new HashMap<Integer, Integer>();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N;i++) {
			int number = Integer.parseInt(st.nextToken());
			map.put(number, 1);
		}
		
		st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<M;i++) {
			int number = Integer.parseInt(st.nextToken());
			if(map.containsKey(number)) System.out.println(1);
			else System.out.println(0);
		}
	}
}
