#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MICROFIREWORKS_PATH_DATA (\
	"public/presentations/microfireworks/data/position-velocity.txt"\
)

int main(void) {
	char buf[128];
	char *ptr_line = NULL;
	size_t size_line = 0;
	errno = 0;
	FILE *file = fopen(MICROFIREWORKS_PATH_DATA, "r");
	if (!file) {
		if (errno) {
			fprintf(stderr, "error: %s\n", strerror(errno));
		}
		exit(EXIT_FAILURE);
	}

	int idxLine = 0;
	ssize_t bytes_read = 0;
	do {
		char tab = 0;
		char newLine = 0;
		double position = 0;
		double velocity = 0;
		bytes_read = getline(&ptr_line, &size_line, file);
		fprintf(stdout, "%s", ptr_line);
		char *headDelim = strstr(ptr_line, ":");
		if (!headDelim && (1 < bytes_read)) {
			memset(buf, 0, sizeof(buf));
			memcpy(buf, ptr_line, sizeof(buf));
			buf[sizeof(buf) - 1] = 0;
			int rc = sscanf(buf, "%lf%c%lf%c", &position, &tab, &velocity, &newLine);
			if (4 != rc) {
				fprintf(stderr, "data scan failed at line %d\n", idxLine);
			}
			else {
				fprintf(stdout, "position: %lf velocity: %lf\n", position, velocity);
			}
		}
		++idxLine;
	} while (-1 != bytes_read);

	free(ptr_line);
	ptr_line = NULL;
	size_line = 0;
	fclose(file);
	return 0;
}

// TODO:
// [ ] read the scaling data at the head of the data file
// [ ] define an array of suitable size to store the position velocity data, just count the number of rows in the tabulated section to determine this at runtime
// [ ] perform the scaling from pixels to the position and velocity units
// [ ] check the limiting cases of pure diffusion c(r) = 1/r and
//     reaction-diffusion exp(-r)/r; don't forget that you have to determine ln(c_\inf).
//     Just checking if the data follows a linear trend in any of these is sufficient.
// [ ] store results in another data file
// [ ] use gnuplot to plot results
//
// NOTES:
// Why use Python to spoil all the fun, but seriously a zero-dependency code is always
// better than Python.
//
// The header of the data file has either just a new line or a colon (:) with more
// characters and so it's easy to know when the tabulated data starts.
