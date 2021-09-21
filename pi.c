#include <stdio.h>

int r[500000 + 1];
int c = 0;
int b, d, i, k;

int main() {
	for (int i = 0; i < 500000; i++) {
		r[i] = 2000;
	}
	for (k = 500000; k > 0; k -= 14) {
		d = 0;
		i = k;
		for (;;) {
			d += r[i] * 10000;
			b = 2 * i - 1;
			r[i] = d % b;
			d /= b;
			i--;
			if (i == 0) {
				break;
			}
			d *= i;
		}
		printf("%.4d", c + d / 10000);
		c = d % 10000;
	}
	printf("\n");
	return 0;
}
