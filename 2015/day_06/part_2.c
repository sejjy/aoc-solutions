#include <stdio.h>
#include <string.h>

#define INPUT_LINE_LEN 40
#define ACTION_LEN 8
#define WIDTH  1000
#define HEIGHT 1000

void parse_line(const char *line,
                char *action,
                int *x1, int *y1,
                int *x2, int *y2);
void do_action(int grid[HEIGHT][WIDTH],
               const char *action,
               const int x1, const int y1,
               const int x2, const int y2);
int total_brightness(int grid[HEIGHT][WIDTH]);

int main(void)
{
	int grid[HEIGHT][WIDTH] = {0};
	char line[INPUT_LINE_LEN + 1];
	char action[ACTION_LEN + 1];
	int x1, y1;
	int x2, y2;

	while ((fgets(line, sizeof(line), stdin)) != NULL) {
		parse_line(line, action, &x1, &y1, &x2, &y2);
		do_action(grid, action, x1, y1, x2, y2);
	}

	printf("%d\n", total_brightness(grid));
	
	return 0;
}

void parse_line(const char *line,
                char *action,
                int *x1, int *y1,
                int *x2, int *y2)
{
	sscanf(line, "%s", action);
	if (strcmp(action, "turn") == 0) {
		strcat(action, " ");
		sscanf(line + strlen(action),
		       "%s",
		       action + strlen(action));
	}
	sscanf(line + strlen(action),
	       "%d,%d through %d,%d",
	       x1, y1, x2, y2);
}

void do_action(int grid[HEIGHT][WIDTH],
               const char *action,
               const int x1, const int y1,
               const int x2, const int y2)
{
	int x, y;

	if (strcmp(action, "turn on") == 0) {
		for (y = y1; y <= y2; y++)
			for (x = x1; x <= x2; x++)
				grid[y][x] += 1;
	} else if (strcmp(action, "turn off") == 0) {
		for (y = y1; y <= y2; y++)
			for (x = x1; x <= x2; x++)
				if (grid[y][x] > 0)
					grid[y][x] -= 1;
	} else { // toggle
		for (y = y1; y <= y2; y++)
			for (x = x1; x <= x2; x++)
				grid[y][x] += 2;
	}
}

int total_brightness(int grid[HEIGHT][WIDTH])
{
	int x, y;
	int brightness = 0;

	for (y = 0; y < HEIGHT; y++)
		for (x = 0; x < WIDTH; x++)
			brightness += grid[y][x];
	return brightness;
}
