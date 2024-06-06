#include <stdlib.h>
#include <error_handling.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	FILE* error_file = freopen("error_file.txt", "w+", stderr);
	if (!error_file) {
		printf("Could not freopen error file.\n");
		return EXIT_FAILURE;
	}

	error_debug("This is a test error with number %d and %u.\n", 12, 2u);

	fseek(error_file, 0, SEEK_SET);
	char error_output[1024] = {0};
	fread(error_output, 1, 1024, error_file);
	if (strcmp(error_output, "This is a test error with number 12 and 2.\n") != 0) {
		printf("Unexpected output in stderr.\n");
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}
