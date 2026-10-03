#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MICROFIREWORKS_PATH_DATA (\
	"public/presentations/microfireworks/data/position-velocity.txt"\
)

#define MICROFIREWORKS_MAX_NUMEL 256
#define MICROFIREWORKS_BUF_SIZE 128

int main(void) {
	char buf[MICROFIREWORKS_BUF_SIZE];
	double positions[MICROFIREWORKS_MAX_NUMEL];
	double velocities[MICROFIREWORKS_MAX_NUMEL];
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

	double xmax = 0;
	double ymax = 0;
	double width = 0;
	double height = 0;
	int idxLine = 0;
	int numRows = 0;
	ssize_t bytes_read = 0;
	do {
		char tab = 0;
		char space = 0;
		char newLine = 0;
		double position = 0;
		double velocity = 0;
		char xmaxProp[] = "xmax:";
		char ymaxProp[] = "ymax:";
		char widthProp[] = "width:";
		char heightProp[] = "height:";

		fprintf(stdout, "rows: %d\n", numRows);
		if (MICROFIREWORKS_MAX_NUMEL <= numRows) {
			fprintf(stderr, "%s\n", "datafile exceeds expected number of rows");
			free(ptr_line);
			ptr_line = NULL;
			size_line = 0;
			fclose(file);
			exit(EXIT_FAILURE);
		}

		bytes_read = getline(&ptr_line, &size_line, file);

		if (MICROFIREWORKS_BUF_SIZE <= size_line) {
			fprintf(stderr, "%s\n", "line exceeds expected number of bytes");
			free(ptr_line);
			ptr_line = NULL;
			size_line = 0;
			fclose(file);
			exit(EXIT_FAILURE);
		}

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

			positions[numRows] = position;
			velocities[numRows] = velocity;

			++numRows;
		}
		else {
			char *prop = strstr(ptr_line, widthProp);
			if (prop) {
				int rc = sscanf(prop + (sizeof(widthProp) - 1), "%c%lf%c", &space, &width, &newLine);
				if (3 != rc) {
					fprintf(stderr, "property scan failed at line %d\n", idxLine);
				}
				fprintf(stdout, "width: %lf\n", width);
			}

			prop = strstr(ptr_line, heightProp);
			if (prop) {
				int rc = sscanf(prop + (sizeof(heightProp) - 1), "%c%lf%c", &space, &height, &newLine);
				if (3 != rc) {
					fprintf(stderr, "property scan failed at line %d\n", idxLine);
				}
				fprintf(stdout, "height: %lf\n", height);
			}

			prop = strstr(ptr_line, xmaxProp);
			if (prop) {
				int rc = sscanf(prop + (sizeof(xmaxProp) - 1), "%c%lf%c", &space, &xmax, &newLine);
				if (3 != rc) {
					fprintf(stderr, "property scan failed at line %d\n", idxLine);
				}
				fprintf(stdout, "xmax: %lf\n", xmax);
			}

			prop = strstr(ptr_line, ymaxProp);
			if (prop) {
				int rc = sscanf(prop + (sizeof(ymaxProp) - 1), "%c%lf%c", &space, &ymax, &newLine);
				if (3 != rc) {
					fprintf(stderr, "property scan failed at line %d\n", idxLine);
				}
				fprintf(stdout, "ymax: %lf\n", ymax);
			}
		}
		++idxLine;
	} while (-1 != bytes_read);

	if (!xmax || !ymax || !width || !height) {
		fprintf(stderr, "%s\n", "property scan failure");
		free(ptr_line);
		ptr_line = NULL;
		size_line = 0;
		fclose(file);
		exit(EXIT_FAILURE);
	}

	double const widthInv = 1.0 / width;
	double const heightInv = 1.0 / height;
	double const xscale = xmax * widthInv;
	double const yscale = ymax * heightInv;
	for (int i = 0; i != numRows; ++i) {
		positions[i] *= xscale;
	}

	for (int i = 0; i != numRows; ++i) {
		velocities[i] *= yscale;
	}

	for (int i = 0; i != numRows; ++i) {
		fprintf(stdout, "position: %lf\tvelocity: %lf\n", positions[i], velocities[i]);
	}

	free(ptr_line);
	ptr_line = NULL;
	size_line = 0;
	fclose(file);
	return 0;
}

// TODO:
// [x] read the scaling data at the head of the data file
// [x] define an array of suitable size to store the position velocity data, just count the number of rows in the tabulated section to determine this at runtime
// [x] perform the scaling from pixels to the position and velocity units
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
//
// I know that no line in the data file exceeds 80 characters and so a buffer of 128
// bytes is sufficient. A safety-net has been added just in case this no longer becomes
// true in the future.
