#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../tools/files.h"

char *num_strings[9U] = {
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};

int is_string_digit(char *str) {
	int result = -1;

	for(int i = 0; i < 9; i++) {
		if(strlen(str) >= strlen(num_strings[i])) {
			if(!memcmp(str, num_strings[i], strlen(num_strings[i]))) {
				result = i+1;
				break;
			}			
		}
	}

	return result;
}

char tmp[1024];

int main(void) {
	FILE *ifp = open_input_file("input.txt");
	char *data = read_input_file(ifp);
	char *ptr = data;
	int total = 0;



	while(*ptr != '\0') {
		int len = 0;
		int val = 0;
		int cal = 0;

		for(len = 0; (ptr[len] != '\n') && (ptr[len] != '\0'); len++) {
			tmp[len] = ptr[len];
		}
		//len++;

		tmp[len] = '\0';
		//printf("%s\n", tmp);

		for(int i = 0; i < len; i++) {
			val = is_string_digit(&tmp[i]);
			if(val > -1) {
				cal += val*10;
				printf("first digit = %d\n", val);
				break;
			}

			if(isdigit(tmp[i])) {
				cal += ((tmp[i] - '0') * 10);
				printf("first digit = %d\n", tmp[i] - '0');
				break;
			}
		}

		for(int i = (len-1); i >= 0; i--) {
			val = is_string_digit(&tmp[i]);
			if(val > -1) {
				cal += val;
				printf("second digit = %d\n", val);
				break;
			}

			if(isdigit(tmp[i])) {
				cal += (tmp[i] - '0');
				printf("second digit = %d\n", tmp[i] - '0');
				break;
			}
		}
		printf("val = %d\n\n", cal);
		

		total+=cal;
		ptr+=len+1;
	}

	printf("total: %d\n", total);
}