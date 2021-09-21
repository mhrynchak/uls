#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
	double s = 1;

	for (unsigned int i = 0; i < pow; i++)
		s *= n;
	return s;
}
