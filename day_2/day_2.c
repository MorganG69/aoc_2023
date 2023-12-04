#include <stdio.h>
#include "../tools/files.h"

int main(void) {
	FILE *ifp = open_input_file("input.txt");
	char *data = read_input_file(ifp);

	
}