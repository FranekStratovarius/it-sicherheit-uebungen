#include <stdio.h>
#include <stdlib.h>
int main() {

	FILE *file;
	file = fopen("assets/text.txt", "r");
	int c = fgetc(file);
	int max = 0;
	while (c != EOF) {
		printf("%i\n", c);
		if (c > max) {
			max = c;
		}
		c = fgetc(file);
	}

	printf("max %i\n", max);
	return 0;
}