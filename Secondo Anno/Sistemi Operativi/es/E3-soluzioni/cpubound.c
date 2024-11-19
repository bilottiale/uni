#include <math.h>	/* sqrt() */
#include <stdlib.h>	/* exit() */

#define COUNT 65000

int main(void) {

	int i, j;
	double sqr, val;

	for (i = 1; i < COUNT; i++) {
		for (j = 1; j < COUNT; j++) {

			sqr = sqrt(i * j);
			val = val + 0.1 * sqr;
		}
	}

	exit(EXIT_SUCCESS);
}
