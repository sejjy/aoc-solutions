#include <stdio.h>

int main(void)
{
	int ch;
	int floor = 0;
	int pos = 0;

	while ((ch = getchar()) != EOF) {
		if      (ch == '(') floor++;
		else if (ch == ')') floor--;
		pos++;
		if (floor < 0) break;
	}

	printf("%d\n", pos);

	return 0;
}
