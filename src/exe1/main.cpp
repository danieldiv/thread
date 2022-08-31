#include "mythread.h"

int main() {
	pthread_t monit;

	if ((pthread_create(&monit, NULL, wait, NULL)) != 0) {
		printf("Failed to create thread\n");
		exit(EXIT_FAILURE);
	}

	printf("iniciou com sucesso\n");
	printf("finalizou o main\n");

	pthread_join(monit, NULL);

	return EXIT_SUCCESS;
}