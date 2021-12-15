#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int num1, num2;
		int res;
		scanf("%d%d", &num1, &num2);
		if (num1 >= 1 && num1 <= 9 && num2 >= 1 && num2 <= 9) {
			res = num1 * num2;
		}
		else {
			res = -1;
		}
		printf("#%d %d\n", i + 1, res);
	}
	return 0;
}