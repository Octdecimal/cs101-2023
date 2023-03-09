#include <stdio.h>

int main() {
	FILE* fp = fopen("main2.c", "r");
	if (fp == NULL) {
        printf("Error opening main.c\n");
        return 1;
    }

	FILE* fq = fopen("main2.txt", "w");
	if (fq == NULL) {
        printf("Error creating main.txt!\n");
        return 1;
    }

	fseek(fp, 0L, SEEK_END);
	long int filesize = ftell(fp);
	fseek(fp, 0L, SEEK_SET);

	char a[filesize];
	fread(a, filesize, 1, fp);
	for(int i = 0; i < filesize; i++) {
		fprintf(fq, "%c", a[i]);
		printf("%c", a[i]);
	}

	fclose(fp);
	fclose(fq);
	
	return 0;
}