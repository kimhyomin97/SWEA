// boj 9012 °ıÈ£
#include <cstdio>
int num;

int main(){
	scanf("%d", &num);
	
	char line[51];
	for(int i=0; i<num; i++){
		scanf("%s", &line);
		int offset = 0;
		bool flag = true;
		for(int j=0; line[j]; j++){
			if(line[j] == '('){
				offset++;
			}
			else if(line[j] == ')'){
				if(offset == 0){
					flag = false;
					break;
				}
				else{
					offset--;
				}
			}
		}
		if(flag){
			if(offset == 0) printf("YES\n");
			else printf("NO\n");
		}
		else{
			printf("NO\n");	
		}
	}
	
	
	return 0;
} 
