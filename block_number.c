#include <stdio.h>

void main()
{
	int i, j = 0;
	long offset;
	FILE *fp;
	char *numberp = "1234567890";

	if ((fp = fopen("./block.log", "w+")) == NULL) {
		printf("open failed\n");
		return;
	}

	do {
		rewind(fp);
		offset = (1 << 10) * 24 * j++;
		fseek(fp, offset, 0);

		for (i = 0; i <= 9; i++) {
			fputs(numberp, fp);
		}
	}while(j != 4);

/*	
	char ch = fgetc(fp);
	while(ch != EOF) {
		putchar(ch);
		ch = fgetc(fp);
	}
*/

	printf("%ld\n", offset);

	fclose(fp);
}
