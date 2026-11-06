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
	int vowels = 0;
	int pairs = 0;

	for (size_t i = 0; i < strlen(s); i++) {
		switch (s[i]) {
			case 'a': if (s[i + 1] == 'b') return false; // fall through
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				vowels++;
				break;
			case 'c': if (s[i + 1] == 'd') return false; break;
			case 'p': if (s[i + 1] == 'q') return false; break;
			case 'x': if (s[i + 1] == 'y') return false; break;
		}
		if (s[i] == s[i + 1]) pairs++;
	}
	return vowels >= 3 && pairs >= 1;
}
