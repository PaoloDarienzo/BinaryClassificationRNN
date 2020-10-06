#include <stdio.h>

#define PI 3.14159265

#define DIV 1024

static double swat(double f, double R, double t, double r, double g) {
	double S;
	double x, y;
	double xx, yy;
	double Rt;
	double P;
	double z, q;

	int u, v;
	int i, j;
	int k;

	Rt = R - t - f;
	Rt *= Rt;
	z = g - 2 * f;
	q = (z * (1 - DIV)) / (2 * DIV);
	S = 0;

	if (z <= 0) {
		return 1;
	}

	k = 0;

	for (v = 0; ; v++) {
		y = r + .5 * g + (g + 2 * r) * v;

		if (y > R + g) {
			break;
		}

		for (u = 0; ; u++) {
			x = r + .5 * g + (g + 2 * r) * u;

			if (x > R + g) {
				break;
			}

			for (j = DIV, yy = y + q; j > 0; j--, yy += z / DIV) {
				for (i = DIV, xx = x + q; i > 0; i--, xx += z / DIV) {
					if (xx * xx + yy * yy < Rt) {
						k++;
					}
				}
			}
		}
	}

	S = 4 * k * z * z / (DIV * DIV);

	P = 1.0 - (S / (PI * R * R));

	if (P < 0) {
		P = 0;
	}

	if (P > 1) {
		P = 1;
	}

	return P;
}

int main(int argc, char **argv, char **envp) {
	FILE *f;
	int numCases;
	int i;

	float _f, R, t, r, g;

	if (argc < 2) {
		printf("usage: %s input_file_name\n", argv[0]);
		return 0;
	}

	f = fopen(argv[1], "r");

	if (f == NULL) {
		fprintf(stderr, "unable to open input file\n");
		goto errOpen;
	}

	fscanf(f, "%d\n", &numCases);

	for (i = 0; i < numCases; i++) {
		fscanf(f, "%f %f %f %f %f\n", &_f, &R, &t, &r, &g);

		printf("Case #%d: %f\n", i + 1, swat(_f, R, t, r, g));
	}

	fclose(f);

errOpen:
	return -1;
}
