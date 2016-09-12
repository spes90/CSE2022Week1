#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

double getRandomNum(const double min, const double max);

bool isInsidecircle(const double x, const double y) {
	const double x_c = 0.5;
	const double y_c = 0.5;
	const double r = 0.5;

	double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;

	if (f > 0.0)
		return false;
	else
		return true;
}

double getRandomNum(const double min, const double max) {
	double tmp = (double)rand() / (double)RAND_MAX;
	tmp = min + (max - min)*tmp;
	return tmp;
}

void main() {
	FILE *of = fopen("pi.txt", "w");

	
	srand((unsigned int)(time(NULL)));

	for (int area_square = 10; area_square < 100000000; area_square *= 2) {

		int area_circle = 0;

		for (int i = 0; i < area_square; i++) {
			double x = getRandomNum(0.0, 1.0);
			double y = getRandomNum(0.0, 1.0);

			if (isInsidecircle(x, y) == true) {
				area_circle++;
			}
		}
			const double pi = 4.0 * (double)area_circle / (double)area_square;
			printf("%f\n", pi);
			fprintf(of, "Estimate Pi in %d times is %f\n", area_square, pi);
	}

		fclose(of);
}
