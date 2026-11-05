#include <stdio.h>

int min(int a, int b, int c);

int main(void)
{
	int l, w, h;
	int len, total = 0;

	while (scanf("%dx%dx%d", &l, &w, &h) == 3) {
		len = 2 * min(l + w, l + h, w + h) + (l * w * h);
		total += len;
	}

	printf("%d\n", total);

	return 0;
}

int min(int a, int b, int c)
{
	int min = a;
	if (b < min) min = b;
	if (c < min) min = c;
	return min;
}
