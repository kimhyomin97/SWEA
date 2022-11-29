import java.util.*;
import java.io.*;

public class BOJ_4179_불 {
	public static class info{
		int row;
		int col;
		public info(int row, int col) {
			this.row = row;
			this.col = col;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] line = br.readLine().split(" ");
		int r = Integer.parseInt(line[0]);
		int c = Integer.parseInt(line[1]);
		char[][] map = new char[r][c]; // 지도를 담는 배열
		Queue<info> jihun = new LinkedList<>(); // 지훈이가 이동 가능한 위치를 담을 큐
		Queue<info> fire = new LinkedList<>(); // 불이 이동 가능한 위치를 담을 큐
		for(int i=0; i<r; i++) {
			String[] temp = br.readLine().split("");
			for(int j=0; j<c; j++) {
				map[i][j] = temp[j].charAt(0);
				if(map[i][j] == 'J') jihun.add(new info(i, j)); // 지훈이의 위치 저장
				if(map[i][j] == 'F') fire.add(new info(i, j)); // 불의 위치 저장
			}
		}
		
		int[] dr = {1, -1, 0, 0}; // 하, 상, 우, 좌 순차적으로 이동
		int[] dc = {0, 0, 1, -1}; // 하, 상, 우, 좌 순차적으로 이동
		int ans = 0; // 지훈이가 이동한 거리를 담는 변수
		
		while(jihun.size() != 0) { // 지훈이가 이동 가능한 위치가 없다면 반복문 종료
			ans++; // 지훈이가 한칸 이동할때 이동한 거리 증가
			int len = fire.size(); // 한칸 이동하는 시점에 이동 가능한 불의 개수 저장 // 큐를 poll 할때마다 길이가 달라지기 때문에 미리 저장
			for(int i=0; i<len; i++) {
				info now = fire.poll(); // 큐에서 위치값 하나씩 빼주는 작업
				for(int j=0; j<4; j++) {
					int nr = now.row + dr[j]; // 상하좌우로 이동한 값
					int nc = now.col + dc[j];
					try{ // 배열 바깥의 범위로 이동하면 ArrayIndexOutOfBounds 오류를 캐치함
						if(map[nr][nc] == '.' || map[nr][nc] == 'J') { // 불이 이동 가능한 위치는 '.'과 지훈이가 이동 가능한 위치
							map[nr][nc] = 'F'; // 지도의 값을 불로 바꿔주면 visit 배열 사용하지 않아도 됨
							fire.add(new info(nr, nc)); // 불을 큐에 뒤쪽으로 넣어줌
						}
					}catch(Exception e) {}
				}
			}
			len = jihun.size(); // 불이 이동한 방식 그대로 지훈이가 이동
			for(int i=0; i<len; i++) {
				info now = jihun.poll();
				for(int j=0; j<4; j++) {
					int nr = now.row + dr[j];
					int nc = now.col + dc[j];
					try {
						if(nr == -1 || nc == -1 || nr == r || nc == c) {
							System.out.println(ans); // 밖으로 탈출 가능한 경우 정답을 출력하고 프로그램 종료
							return;
						}
						if(map[nr][nc] == '.') {
							map[nr][nc] = 'J';
							jihun.add(new info(nr, nc));
						}
					}catch(Exception e) {}
				}
			}
		}
		System.out.println("IMPOSSIBLE"); // 나갈 수 없는 경우 지훈이의 이동 가능한 경로가 0이 되기 때문에 IMPOSSIBLE 리턴하고 종료
	}
}
