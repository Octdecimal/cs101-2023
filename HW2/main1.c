#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int n;
    int lotto[7];
    FILE* fp;
    time_t curtime;
    time(&curtime);
    fp = fopen("lotto.txt", "w+");
    if(fp == NULL) {
        printf("Error creat file\n");
        reutrn 1;
    }
    srand((unsigned) time(NULL));
    
    printf("  �w����{�����ֳz�m�R�ʶR���x\n  �аݱz�n�R�X�ռֳz�m�G");
    scanf("%d", &n);
    
    fprintf(fp, "======== lotto649 ========\n");
    fprintf(fp, " %s", ctime(&curtime));
    for(int i = 1; i < 6; i++) {
        fprintf(fp, "[%d]: ", i);
        if(i <= n) {
            for(int j = 0; j < 7; j++) {
                if(j != 6) {
                    lotto[j] = rand() % 68 + 1;
                } else {
                    lotto[j] = rand() % 9 + 1;
                }
            fprintf(fp, "%02d ", lotto[j]);
            }    
        } else {
            for(int j = 0; j < 7; j++) {
                fprintf(fp, "-- ");
            }
        }
        fprintf(fp, "\n");
    }

    fprintf(fp, "======== csie@cgu ========");
    fclose(fp);
    
    printf("  �w���z�ʶR�� %d �ռֳz�զX��X��  lotto.txt", n);
    
    return 0;
}
