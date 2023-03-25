#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int receipt_id;
    int receipt_price;
    char receipt_time[32];
    int lotto_set[5][7];
} lotto_record;

void randomLotto(lotto_record *rc, int i, int j) {
    if(j != 6) {
         rc->lotto_set[i][j] = rand() % 69 + 1;
    } else {
        rc->lotto_set[i][j] = rand() % 10 + 1;
    }
    for(int x = 0; x < j; x++) {
        if(rc->lotto_set[i][x] != rc->lotto_set[i][j]) {
            return;
        } else {
            randomLotto(rc, i, j);
        }
    }
}

void lottoChecker(FILE* record, int price[3]) {
    int total = 0;
    lotto_record rc;
    rewind(record);
    printf("\n�H�U�������m��G\n");
    while(fread(&rc, sizeof(lotto_record), 1, record)) {
        for(int i = 0; i < 5; i++) {
            int match = 0;
            for(int j = 0; j < 7; j++) {
                for(int k = 0; k < 3; k++) {
                    if(rc.lotto_set[i][j] == price[k]) {
                        match++;
                        total++;
                    }
                }
            }
            if(match != 0) {
                printf("�m�� No. %d\n��X�ɶ��G%s\n���X�G",rc.receipt_id, rc.receipt_time);
                for(int k = 0; k < 7; k++) {
                    printf("%02d ",rc.lotto_set[i][k]);
                }
                printf("\n\n");
                match = 0;
            }
        }
    }
    if(!total) {
        printf("�z���ʶR���m��å�����\n");
    }
}

void LottoCreater(int i, lotto_record *rc) {
    char filename[20];
    sprintf(filename, "lotto%05d.txt", rc->receipt_id);
    FILE* fp = fopen(filename, "w+");
    int n;

    time_t t;
    time(&t);
    srand((unsigned) time(NULL));
    strftime(rc->receipt_time, sizeof(rc->receipt_time), "%a %b %d %X %Y", gmtime(&t));
    sprintf(filename ,"lotto[%05d]", rc->receipt_id);
    if(fp == NULL) {
        printf("\nError creat %s\n", filename);
        exit(1);
    } else {
        printf("\n�������z�ʶR����%d�i�m��,�аݱz�n�R�X�ռƦr�G", i);
    }
    scanf("%d", &n);
    fprintf(fp, "========= lotto649 =========\n========+ NO.%05d +========\n= %s =\n", rc->receipt_id, rc->receipt_time);
    for(int i = 0; i < 5; i++) {  
        fprintf(fp, " [%d]: ", i+1);
        if(i < n) {
            for(int j = 0; j < 7; j++) {
                randomLotto(rc, i, j);
                fprintf(fp, "%02d ", rc->lotto_set[i][j]);
            }    
        } else {
            for(int j = 0; j < 7; j++) {
                rc->lotto_set[i][j] = -1;
                fprintf(fp, "-- ");
            }
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "========= csie@cgu =========");
    fclose(fp);
    printf("  �w���z�ʶR�� %d �ռֳz�զX��X��  lotto%05d.txt\n", n, rc->receipt_id);
    rc->receipt_price = 100 * i;
}

int main() {
    lotto_record rc;
    FILE* record = fopen("record.bin", "ab+");
    if(fread(&rc, sizeof(lotto_record), 1, record)) {
        while(fread(&rc, sizeof(lotto_record), 1, record)) {
            continue;
        }
        rc.receipt_id++;
    } else {
        rc.receipt_id = 1;
    }
	int code = 1, price[3] = {0, 0, 0};
    char input[32];
    while(code != 0) {
        printf("�аݱz�n�R�X�ռֳz�m�G");
	    scanf("%d", &code);
        fflush(stdin);
	    if(code == 0) {
	    	printf("�п�J�������X (�̦h�T��)�G");
        	scanf("%31[^\n]", input);
            for(int i = 0, j = 0, k = 0; i < 31; i++) {
                if(input[i] > '0' && input[i] <= '9') {
                    price[j] = 10 * price[j] + input[i] - '0';
                    k++;
                }
                if(k == 2 || (price[j] != 0 && input[i+1] == ' ')) {
                    j++;
                    k = 0;
                }
                if(j == 3) {
                    break;
                }
            }
            printf("��J�������X���G ");
            for(int i = 0; i < 3; i++) {
                printf("%d ", price[i]);
            }
            lottoChecker(record, price);
    	} else {
            for(int i = 0; i < code; i++) {
    	        LottoCreater(i+1, &rc);
                if(!rc.receipt_price) {
                    fwrite(&rc, sizeof(lotto_record), 1, record);
                    rc.receipt_id++;
                }
            }
        }
    }
	fclose(record);
    return 0;
}
