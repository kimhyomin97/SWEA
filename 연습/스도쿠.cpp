// boj 2580 ½ºµµÄí
#include <cstdio>

int main(){
	int map[9][9];
	int cnt=0;
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 0) cnt++;
		}
	}
	while(cnt > 0){
	
		for(int i=0; i<9; i++){
			bool temp[9] = {false,};
			int index = -1;
			int blank_cnt = 0;
			for(int j=0; j<9; j++){
				if(map[i][j] == 0) {
					index = j;
					blank_cnt++;
				}
				else
					temp[map[i][j]-1] = true;
			}
			if(index != -1 && blank_cnt == 1){
				for(int j=0; j<9; j++){
					if(temp[j] == false) {
						map[i][index] = j+1;
						cnt--;
					}
				}
			}
		}
		for(int i=0; i<9; i++){
			bool temp[9] = {false,};
			int index = -1;
			int blank_cnt = 0;
			for(int j=0; j<9; j++){
				if(map[j][i] == 0) {
					index = j;
					blank_cnt++;
				}
				else
					temp[map[j][i]-1] = true;
			}
			if(index != -1 && blank_cnt == 1){
				for(int j=0; j<9; j++){
					if(temp[j] == false) {
						map[index][i] = j+1;
						cnt--;
					}
				}
			}
		}
		for(int i=0; i<9; i+=3){
			for(int j=0; j<9; j+=3){
				bool temp[9] = {false,};
				int index_row = -1;
				int index_col = -1;
				int blank_cnt = 0;
				for(int k=0; k<3; k++){
					for(int m=0; m<3; m++){
						if(map[k+i][m+j] == 0){
							index_row = k;
							index_col = m;
							blank_cnt++;
						}
						else
							temp[map[k+i][m+j]-1] = true;
					}
				}
				if(index_row != -1 && index_col != -1 && blank_cnt == 1){
					for(int k=0; k<9; k++){
						if(temp[k] == false){
							map[index_row+i][index_col+j] = k+1;
							cnt--;
						}
					}
				}
			}
		}
		
	}
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	
	return 0;
} 
