#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char **argv) {
	int buflen;
	int count;
	char *input_buffer;
	long xor_value;

	buflen = 2048;
	xor_value = 255;
	if (argc > 1) {
		errno = 0;
		xor_value = strtol(argv[1], NULL, 10);
		if (errno || xor_value < 0 || xor_value > 255) {
			fprintf(stderr, "aborting: bad value specified.\n");
			return EXIT_FAILURE;
		}
	}
	input_buffer = (char *)malloc(buflen*sizeof(char));
	if (input_buffer == NULL) {
		fprintf(stderr, "aborting: malloc() failed.\n");
		return EXIT_FAILURE;
	}
	
	while ((count = read(0,input_buffer,sizeof(input_buffer)))) {
		for (int i = 0; i<count;  i++) {
			input_buffer[i] ^= xor_value;
		}
		write(1,input_buffer,count);
	}

	return EXIT_SUCCESS;
}

