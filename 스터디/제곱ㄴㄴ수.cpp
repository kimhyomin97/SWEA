// boj 1016 Á¦°ö ¤¤¤¤ ¼ö
#include <cstdio>

int main(){
	long long min, max;
	scanf("%lld %lld", &min, &max);
	long long cnt = 0;
	
	bool list[max-min+1] = {false,};
	
	for(long long i = 2; i*i<=max; i++){
		long long j = min / (i*i);
		if(min % (i*i) != 0) j++;
		for(; i*i*j <= max; j++){
//			list[i*i*j-min] = true;
			if(list[i*i*j-min] == false){
				list[i*i*j-min] = true;
				cnt++;
			}
		}
	}
//	for(int i=0; i<max-min+1; i++){
//		if(list[i] == true) cnt++;
//	}
	printf("%lld", max-min+1-cnt);
	return 0;
}
