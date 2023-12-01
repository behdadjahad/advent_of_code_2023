#include <stdio.h>
#include <stdlib.h>


int main()
{
	FILE *f = fopen("input.txt", "r");
	if (f == NULL) {
		printf("can not open the file.\n");
		return -1;
	}


	int sum = 0;

	char c;
	int first_num = -1;
	int last_num = -1;
	while ((c=fgetc(f)) != EOF) {
		if (c < 58 && c > 47) {
			if (first_num == -1) {
				first_num = (int)c - 48; 
			} else {
				last_num = (int)c - 48;
			}
		}		

		if (last_num == -1 && first_num != -1) {
			last_num = first_num;
		}
		
		if (first_num != -1  && c == '\n') {
			sum += (first_num * 10) + last_num;
			first_num = -1;
			last_num = -1;
		}
	}

	printf("%d\n", sum);


	fclose(f);
	return 0;
}
