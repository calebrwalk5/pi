#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int r[2800 + 1];
int c = 0;
int g = 0;
int b, d, i, k, z;

void *multiThread(void *vargp) {
	int *threadid = (int *)vargp;
	static int s = 0;
	s++;
	g++;
	printf("Thread ID: %d, Static: %d, Global: %d\n", *threadid, s++, g++);	
}

void piCalc() {
	for (int i = 0; i < 2800; i++) {
		r[i] = 2000;
	}
	for (k = 2800; k > 0; k -= 14) {
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
}

int main() {
    	pthread_t tid;
    	for (z = 0; z < 5; z++)
        	pthread_create(&tid, NULL, multiThread, (void *)&tid);
		piCalc();
    	pthread_exit(NULL);
    	return 0;
}
