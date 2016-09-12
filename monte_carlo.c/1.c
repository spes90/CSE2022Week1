#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

double getRandNum(const double min, const double max);

bool isInsidecircle(const double x, const double y) {
	double x_c = 0.5;
	double y_c = 0.5;
	double r = 0.5;

	const double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;
	if (f > 0.0)
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
	FILE *of = fopen("circle.txt", "w");
	srand((unsigned int)(time(NULL)));
	
	for (int i = 0; i < 10000; i++) {
		double x = getRandNum(0.0, 1.0);
		double y = getRandNum(0.0, 1.0);
		if (isInsidecircle(x, y) == true) {
			fprintf(of, "%f, %f\n", x, y);
		}
	}
	fclose(of);
}