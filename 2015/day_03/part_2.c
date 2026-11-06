#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Location {
	int x;
	int y;
	struct Location *next;
};

struct Location *start = NULL;

bool unique_location(struct Location *loc);
void save_location(struct Location *loc);

int main(void)
{
	int ch;
	bool santa_turn = true;
	struct Location santa_loc = {0, 0, NULL};
	struct Location robo_santa_loc = {0, 0, NULL};
	struct Location *loc;
	int houses = 0;

	// starting location
	save_location(&santa_loc);
	houses++;

	while ((ch = getchar()) != EOF) {
		loc = santa_turn ? &santa_loc : &robo_santa_loc;

		switch (ch) {
			case '^': loc->y++; break;
			case 'v': loc->y--; break;
			case '>': loc->x++; break;
			case '<': loc->x--; break;
		}

		if (unique_location(loc)) {
			save_location(loc);
			houses++;
		}
		santa_turn = !santa_turn;
	}

	printf("%d\n", houses);

	return 0;
}

bool unique_location(struct Location *loc)
{
	struct Location *p;

	for (p = start; p != NULL; p = p->next) {
		if (p->x == loc->x && p->y == loc->y)
			return false;
	}
	return true;
}

void save_location(struct Location *loc)
{
	struct Location *new_loc = malloc(sizeof *loc);

	new_loc->x = loc->x;
	new_loc->y = loc->y;
	new_loc->next = NULL;

	if (start == NULL)
		start = new_loc;
	else {
		new_loc->next = start;
		start = new_loc;
	}
}
