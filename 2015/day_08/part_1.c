#include <stdio.h>
#include <string.h>

#define INPUT_LINE_LEN 50

int main(void)
{
	char line[INPUT_LINE_LEN + 1];
	int line_len, i;
	int code_len = 0;
	int data_len = 0;

	while ((fgets(line, sizeof(line), stdin)) != NULL) {
		strtok(line, "\n");
		line_len = strlen(line);
		code_len += line_len;
		for (i = 1; i < line_len - 1; data_len++) {
			if (line[i] == '\\') {
				if (line[i + 1] == 'x')
					i += 4;
				else
					i += 2;
			} else {
				i++;
			}
		}
	}

	printf("%d\n", code_len - data_len);

	return 0;
}
