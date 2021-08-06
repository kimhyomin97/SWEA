// 백준 14891 톱니바퀴
#include <cstdio>

int gear[4][8];
int k;
int ans = 0;

void spin(int num){
//	num--;
	// 시계방향 회전 
	int temp = gear[num][7];
	for(int i=7; i>0; i--){
		gear[num][i] = gear[num][i-1];
	}
	gear[num][0] = temp;
}

void spin_reverse(int num){
//	num--;
	int temp = gear[num][0];
	for(int i=0; i<7; i++){
		gear[num][i] = gear[num][i+1];
	}
	gear[num][7] = temp;
}

int main(){
	for(int i=0; i<4; i++){
		for(int j=0; j<8; j++){
			scanf("%1d", &gear[i][j]);
		}
	}
	scanf("%d", &k);
	bool connect[3] = {false,}; // 0-1   1-2   2-3
	for(int i=0; i<k; i++){
		int num, dir;
		scanf("%d%d", &num, &dir);
		if(gear[0][2] != gear[1][6]) connect[0] = true;
		if(gear[1][2] != gear[2][6]) connect[1] = true;
		if(gear[2][2] != gear[3][6]) connect[2] = true;
//		printf("connect : %d %d %d \n", connect[0], connect[1], connect[2]);
		if(dir == 1){
			spin(num-1);
			int cnt = 0;
			for(int i=num-1; i<3; i++){
				if(connect[i]){
					if(cnt % 2 == 0) spin_reverse(i+1);
					else if(cnt%2 == 1) spin(i+1);
					cnt++;
				}
				else{
					break;
				}
			}
			cnt = 0;
			for(int i=num-1; i>0; i--){
				if(connect[i-1]){
					if(cnt % 2 == 0) spin_reverse(i-1);
					else if(cnt%2 == 1) spin(i-1);
					cnt++;
				}
				else{
					break;
				}
			}
		}
		else if(dir == -1){
			spin_reverse(num-1);
			int cnt = 0;
			for(int i=num-1; i<3; i++){
				if(connect[i]){
					if(cnt % 2 == 0) spin(i+1);
					else if(cnt%2 == 1) spin_reverse(i+1);
					cnt++;
				}
				else{
					break;
				}
			}
			cnt = 0;
			for(int i=num-1; i>0; i--){
//				printf("HEllo\n");
				if(connect[i-1]){
					if(cnt % 2 == 0) spin(i-1);
					else if(cnt%2 == 1) spin_reverse(i-1);
					cnt++;
				}
				else{
					break;
				}
			}
		}
		for(int i=0; i<4; i++) connect[i] = false;
//		printf("\n");
//		for(int i=0; i<4; i++){
//			for(int j=0; j<8; j++){
//				printf(" %d ", gear[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
		}

//	printf("\n");
//	for(int i=0; i<4; i++){
//		for(int j=0; j<8; j++){
//			printf(" %d ", gear[i][j]);
//		}
//		printf("\n");
//	}
//	spin(0);
//	printf("reverse : 3 \n");
//	spin_reverse(3);
//	printf("\n");
//	for(int i=0; i<4; i++){
//		for(int j=0; j<8; j++){
//			printf(" %d ", gear[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");

	if(gear[0][0] == 1) ans +=1;
	if(gear[1][0] == 1) ans +=2;
	if(gear[2][0] == 1) ans +=4;
	if(gear[3][0] == 1) ans +=8;
	printf("%d", ans);
	
	return 0;
} 
