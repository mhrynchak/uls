#include "libmx.h"

void mx_printint(int n) {
	bool isNegative = false;
	int i = 0, tmp = n;
	char ch[11];

	if (tmp < 0) {
		if (n == INT_MIN) tmp++;
		tmp = -tmp;
		isNegative = true;
	}

	else if (tmp == 0) {
		mx_printchar('0');
		return;
	}

	while (tmp > 0) {
		ch[i] = tmp % 10 + '0';
		tmp /= 10;
		i++;
	}

	if (isNegative) {
		if (n == INT_MIN) ch[0]++;
		ch[i] = '-';
	} else i--;

	for (; i >= 0; i--)
		mx_printchar(ch[i]);
}
