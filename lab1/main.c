#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[] = {1, 2, 3};
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3};
    FILE* fp;
    int read[100];
    fp = fopen("a.bin", "wb+");
    fwrite(a, sizeof(int), 3, fp);
    fseek(fp, 0, SEEK_SET);
    fread(read, sizeof(int), 3, fp);
    for(int i=0; i<3; i++) {
        printf("%d", read[i]);
    }
    return 0;
}