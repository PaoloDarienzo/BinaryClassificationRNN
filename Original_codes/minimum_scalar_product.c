#include <stdio.h>
#include <stdlib.h>

int
lessthan(int *a, int *b)
{
	return (*b - *a);
}

int
morethan(int *a, int *b)
{
	return (*a - *b);
}


main()
{
	unsigned T, i;

	scanf("%u\n", &T);

	for (i = 1; i <= T; i++) {
		unsigned n, j;
		long long Y;
		int x[800], y[800];
		
		scanf("%u\n", &n);
		for (j = 0; j < n; j++)
			scanf("%i", &x[j]);
		for (j = 0; j < n; j++)
			scanf("%i", &y[j]);

		qsort(x, n, sizeof(int), &lessthan);
		qsort(y, n, sizeof(int), &morethan);

		for (Y = 0, j = 0; j < n; j++)
			Y += ((long long)x[j] * (long long)y[j]);

		printf("Case #%d: %lld\n", i, Y);
	}
}

//end
