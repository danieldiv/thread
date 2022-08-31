#include "mythread.h"

int main() {
	// chamada com problema de concorrencia
	waitP();

	printf("\n");

	// chamada com problema de concorrencia
	waitC();

	return EXIT_SUCCESS;
}