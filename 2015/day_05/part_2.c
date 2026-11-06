#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define INPUT_STR_LEN 16

bool string_nice(const char *s);

int main(void)
{
	char str[INPUT_STR_LEN + 1];
	int nice_strs = 0;

	while ((fgets(str, sizeof(str), stdin)) != NULL) {
		strtok(str, "\n");
		if (string_nice(str))
			nice_strs++;
	}

	printf("%d\n", nice_strs);

	return 0;
}

bool string_nice(const char *s)
{
	bool repeats = false;
	size_t i, j, len = strlen(s);

	for (i = 0; i + 2 < len; i++) {
		if (s[i] == s[i + 2]) {
			repeats = true;
			break;
		}
	}
	if (!repeats) return false;

	for (i = 0; i < len; i++) {
		for (j = i + 2; j < len; j++) {
			if (s[i] == s[j] && s[i + 1] == s[j + 1])
				return true;
		}
	}
	return false;
}
