#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Location {
	int x;
	int y;
	struct Location *next;
};

struct Location *start = NULL;

bool unique_location(int x, int y);
void save_location(int x, int y);

int main(void)
{
	int ch;
	int x = 0, y = 0;
	int houses = 0;

	// starting location
	save_location(x, y);
	houses++;

	while ((ch = getchar()) != EOF) {
		switch (ch) {
			case '^': y++; break;
			case 'v': y--; break;
			case '>': x++; break;
			case '<': x--; break;
		}

		if (unique_location(x, y)) {
			save_location(x, y);
			houses++;
		}
	}

	printf("%d\n", houses);

	return 0;
}

bool unique_location(int x, int y)
{
	struct Location *p;

	for (p = start; p != NULL; p = p->next) {
		if (p->x == x && p->y == y)
			return false;
	}
	return true;
}

void save_location(int x, int y)
{
	struct Location *loc = malloc(sizeof *loc);

	loc->x = x;
	loc->y = y;
	loc->next = NULL;

	if (start == NULL)
		start = loc;
	else {
		loc->next = start;
		start = loc;
	}
}
