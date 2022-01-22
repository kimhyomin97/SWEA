package ≈ª√‚;

import java.io.*;
import java.util.*;

class Pos{
	int row;
	int col;
	public Pos(int row, int col) {
		this.row = row;
		this.col = col;
	}
}

public class Main {
	static int R;
	static int C;
	static char[][] map;
	static boolean[][] visited;
	static int minCnt;
	static int[] dy = {-1, 1, 0, 0};
	static int[] dx = {0, 0, -1, 1};
	static Queue<Pos> moveQ = new LinkedList<Pos>();
	static Queue<Pos> waterQ = new LinkedList<Pos>();
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		
		map = new char[R][C];
		visited = new boolean[R][C];
		minCnt = Integer.MAX_VALUE;
		for(int i=0; i<R; i++) {
			String str = br.readLine();
			for(int j=0; j<C; j++) {
				char c = str.charAt(j);
				map[i][j] = c;
				if(c == 'S') {
					moveQ.offer(new Pos(i, j));
					visited[i][j] = true;
				}
				else if(c == '*') {
					waterQ.offer(new Pos(i, j));
				}
			}
		}
		
		int move = 0;
		while (!moveQ.isEmpty()) {
			spread();
			bfs(++move);
		}
		
		System.out.println(minCnt == Integer.MAX_VALUE ? "KAKTUS" : minCnt);
		br.close();
	}
	
	private static void bfs(int move) {
		int cnt = moveQ.size();
		
		while(cnt-- > 0) {
			Pos pos = moveQ.poll();
			int row = pos.row;
			int col = pos.col;
			for(int d=0; d<4; d++) {
				int nextRow = row + dy[d];
				int nextCol = col + dx[d];
				
				if(isIn(nextRow, nextCol) && isMove(nextRow, nextCol)) {
					if(map[nextRow][nextCol] == 'D') {
						minCnt = move;
						moveQ.clear();
						return;
					}
				}
				
				if(!visited[nextRow][nextCol]) {
					moveQ.offer(new Pos(nextRow, nextCol));
					visited[nextRow][nextCol] = true;
				}
			}
		}
	}
	
	private static void spread() {
		int cnt = waterQ.size();
		
		while(cnt-- > 0) {
			Pos waterPos = waterQ.poll();
			int row = waterPos.row;
			int col = waterPos.col;
			
			for(int d=0; d<4; d++) {
				//
				//
				//
			}
		}
	}
	
}
