#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *routimeP(void *arg);
void waitP();

void *routimeC(void *arg);
void waitC();

#endif

void *routimeP(void *arg) {
	int data[10] = { 34,5,28,98,56,11,62, 33,89,100 };
	int index = *(int *)arg;

	printf("index: %d value: %d\n", index, data[index]);
	pthread_exit(arg);
}

void waitP() {
	pthread_t th[10];
	int i;

	for (i = 0;i < 10;i++) {
		if ((pthread_create(&th[i], NULL, &routimeP, &i)) != 0) {
			perror("Failed to create thread\n");
		}
	}

	for (i = 0;i < 10;i++) {
		if (pthread_join(th[i], NULL) != 0) {
			perror("Failed to join threads");
		}
	}
}

void *routimeC(void *arg) {
	int data[10] = { 34,5,28,98,56,11,62, 33,89,100 };
	int index = *(int *)arg;

	printf("index: %d value: %d\n", index, data[index]);
	pthread_exit(arg);
}

void waitC() {
	pthread_t th[10];

	for (int i = 0; i < 10; i++) {
		int *a = (int *)malloc(sizeof(int));
		*a = i;

		if ((pthread_create(&th[i], NULL, &routimeC, a)) != 0) {
			perror("Failed to create thread\n");
		}
	}

	for (int i = 0; i < 10; i++) {
		if (pthread_join(th[i], NULL) != 0) {
			perror("Failed to join threads");
		}
	}
}