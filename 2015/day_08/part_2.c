#include <stdio.h>
#include <string.h>

#define INPUT_LINE_LEN 50

int main(void)
{
	char line[INPUT_LINE_LEN + 1];
	int line_len, i;
	int encoded_len = 0;
	int code_len = 0;

	while ((fgets(line, sizeof(line), stdin)) != NULL) {
		strtok(line, "\n");
		line_len = strlen(line);
		encoded_len += 2; // surrounding double quotes
		for (i = 0; i < line_len; i++) {
			if (line[i] == '\\' || line[i] == '"')
				encoded_len += 2;
			else
				encoded_len++;
		}
		code_len += line_len;
	}

	printf("%d\n", encoded_len - code_len);

	return 0;
}
