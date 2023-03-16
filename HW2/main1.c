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
    
    printf("  歡迎光臨長庚樂透彩買購買機台\n  請問您要買幾組樂透彩：");
    scanf("%d", &n);
    
    fprintf(fp, "======== lotto649 ========\n");
    fprintf(fp, " %s", ctime(&curtime));
    for(int i = 1; i < 6; i++) {
        fprintf(fp, "[%d]: ", i);
        if(i <= n) {
            for(int j = 0; j < 7; j++) {
                if(j != 6) {
                    lotto[j] = rand() % 69 + 1;
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
    
    printf("  已為您購買的 %d 組樂透組合輸出至  lotto.txt", n);
    
    return 0;
}
