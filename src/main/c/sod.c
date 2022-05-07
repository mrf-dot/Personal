#include <sodium.h>

int
main() {
	// test libsodium
	if (sodium_init() < 0) {
		printf("Panic!\n");
	}
	for (int i = 1; i < 11; i++) {
		printf("Random #%d:\t%ud\n", i, randombytes_random());
	}
}

