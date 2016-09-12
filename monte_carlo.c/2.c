#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

double getRandNum(const double min, const double max);
bool isInsidecircle2(const double x, const double y);

bool isInsidecircle1(const double x, const double y) {
	double x_c = 0.5;
	double y_c = 0.5;
	double r = 0.5;

	const double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;
	if (f > 0.0)
		return false;
	else
		return true;
}

bool isInsidecircle2(const double x, const double y) {
	double x_c = 2.5;
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
	FILE *of = fopen("dumbbell.txt", "w");
	srand((unsigned int)(time(NULL)));

	for (int i = 0; i < 10000; i++) {
		double a = getRandNum(0.0, 1.0);
		double b = getRandNum(0.0, 1.0);
		double c = getRandNum(2.0, 3.0);
		double d = getRandNum(0.0, 1.0);
		double e = getRandNum(1.0, 2.0);
		double f = getRandNum(0.25, 0.75);
		if (isInsidecircle1(a, b) == true) {
			fprintf(of, "%f, %f\n", a, b);
		}
		if (isInsidecircle2(c, d) == true) {
			fprintf(of, "%f, %f\n", c, d);
		}
		fprintf(of, "%f, %f\n", e, f);
	}
	fclose(of);
}