#include <stdio.h>

int main(void)
{
	int ch;
	int floor = 0;

	while ((ch = getchar()) != EOF) {
		if      (ch == '(') floor++;
		else if (ch == ')') floor--;
	}

	printf("%d\n", floor);

	return 0;
}
