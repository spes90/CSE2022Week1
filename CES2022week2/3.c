#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

double getRandNum(const double min, const double max);

bool isInsideOval(const double x, const double y) {
	double x_c = 0.0;
	double y_c = 0.0;

	const double f = (x - x_c)*(x - x_c) / (3.0 * 3.0) + (y - y_c)*(y - y_c) / (1.0 * 1.0);

	if (f > 1.0)
		return false;
	else
		return true;
}

double getRandNum(const double min, const double max) {

	double temp = (double)rand() / (double)RAND_MAX;
	temp = min + (max - min)*temp;

	return temp;
}

void main() {
	FILE *of = fopen("oval.txt", "w");

	srand((unsigned int)(time(NULL)));
	for (int i = 0; i < 10000; i++) {
		double x = getRandNum(-3.0, 3.0);
		double y = getRandNum(-1.0, 1.0);
		if (isInsideOval(x, y) == true) {
			fprintf(of, "%f, %f\n", x, y);
		}
	}
	fclose(of);
}