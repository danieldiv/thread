#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *wait(void *arg);
void *soma(void *arg);

#endif

void *wait(void *arg) {
	pthread_t thread_a;
	pthread_t thread_b;

	void *resp_a;
	void *resp_b;

	if ((pthread_create(&thread_a, NULL, soma, (void *)("A"))) != 0) {
		printf("Failed to create thread\n");
		exit(EXIT_FAILURE);
	}

	if ((pthread_create(&thread_b, NULL, soma, (void *)("B"))) != 0) {
		printf("Failed to create thread\n");
		exit(EXIT_FAILURE);
	}

	pthread_join(thread_a, &resp_a);
	pthread_join(thread_b, &resp_b);

	printf("thread %s finalizada com sucesso\n", (char *)resp_a);
	printf("thread %s finalizada com sucesso\n", (char *)resp_b);

	pthread_exit(arg);

}

void *soma(void *arg) {
	int aux = 0;

	printf("thread %s iniciou com sucesso\n", (char *)arg);

	while (aux < 10) {
		printf("thread: %s values: %d\n", (char *)arg, aux);
		aux++;
	}

	// finaliza a funcao e retorna o argumento void que foi recebido
	pthread_exit(arg);
}
