#include <stdio.h>

void main()
{
	int i, h, j = 0;
	long offset, stepoff = 0;
	FILE *fp;
	char *numberp = "1234567890";

	if ((fp = fopen("./random.log", "w+")) == NULL) {
		printf("open failed\n");
		return;
	}

	for (h = 0; h <= 50; h++) {
		do {
			rewind(fp);
			offset = (1 << 10) * 24 * j++;
			offset += stepoff;
			fseek(fp, offset, 0);

			for (i = 0; i <= 9; i++) {
				fputs(numberp, fp);
			}
		}while(j != 4);

		stepoff += 100;
		j = 0;
	}

	printf("%ld\n", offset);
	printf("%ld\n", stepoff);

	fclose(fp);
}
