/* A cryptographically random header file with only one dependency */
#include <sys/random.h>
#define NSEEDS 4
#define ULONG_MAX 0xffffffff
#define ROTL(X, K) (((X) << (K)) | ((X) >> (64 - (K))))
static unsigned long seeds[NSEEDS];

extern int
srnd() {
	unsigned long seed, z;
	if (getrandom(&seed, sizeof seed, GRND_NONBLOCK) == -1) {
		return 1;
	}
	for (int i = 0; i < NSEEDS; i++) {
		seed += 0x9e3779b97f4a7c15;
		z = seed;
		z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
		z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
		seeds[i] = z ^ (z >> 31);
	}
	return 0;
}


extern unsigned long
rnd() {
	unsigned long result, t;
	result = ROTL(seeds[1] * 5, 7) * 9;
	t = seeds[1] << 17;
	seeds[2] ^= seeds[0];
	seeds[3] ^= seeds[1];
	seeds[1] ^= seeds[2];
	seeds[0] ^= seeds[3];
	seeds[2] ^= t;
	seeds[3] = ROTL(seeds[3], 45);
	return result;
}

extern int
rndint(int lo, int hi) {
	/* Returns a random number lo (inclusive) - hi (exclusive) */
	hi -= lo;
	return rnd() % (hi - lo) + lo;
}

extern void
shuffle(int *a, int sz) {
	int i, j, tmp;
	/* Fischer-Yates Shuffle */
	for (i = sz - 1; i > 0; i--) {
		j = rndint(0, i+1);
		tmp = a[j];
		a[j] = a[i];
		a[i] = tmp;
	}
}

