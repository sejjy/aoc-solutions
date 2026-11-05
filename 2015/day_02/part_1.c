#include <stdio.h>

int min(int a, int b, int c);

int main(void)
{
	int l, w, h;
	int a, b, c;
	int area, total = 0;

	while (scanf("%dx%dx%d", &l, &w, &h) == 3) {
		a = l * w;
		b = l * h;
		c = w * h;
		area = 2 * (a + b + c);
		total += area + min(a, b, c);
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
