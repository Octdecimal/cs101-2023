#include <stdio.h>
int g_mem[10];

typedef struct my_mm {
	int number;
	int address[10];
	int used_mem[10];
} ym_t;
ym_t mms;

int my_calloc(int n, int size) {
	int need = n * size;
	int count = 0;
	int address;
	int seq = 1;
	for(int i = 0; i < 10; i++) {
		if(mms.address[i] != 0) {
			seq++;
		}
	}
	for(int i = 0; i < 10; i++) {
		if(g_mem[i] == 0) {
			for(int j = 0; j < need; j++) {
				if((g_mem[i + j] == 0) && (i + j < 10)) {
					count++;
				}else {
					count = 0;
				}
				if(count == need) {
					address = (i + j + 1) - count;
					break;
				}
			}
			if(count != 0) {
				break;
			}
		}
	}
	if(count == 0) {
		for(int i = 0; i < 10; i++) {
			printf("%d", mms.used_mem[i]);
		}
		printf(" <- Out of space\n");
		return -1;
	}else {
		mms.address[address] = 1;
		for(int a = address, i = 0; i < count; i++) {
			g_mem[a + i] = seq;
			mms.used_mem[a + i] = 1;
		}
		for(int i = 0; i < 10; i++) {
			printf("%d", mms.used_mem[i]);
		}
		printf("\n");
		return address;
	}
 }

void my_free(int p) { 
	int goal = g_mem[p];
	for(int i = 0; i < 10; i++) {
		if(g_mem[i] == goal) {
			g_mem[i] = 0;
			mms.used_mem[i] = 0;
		}
		printf("%d", mms.used_mem[i]);
	}
	printf("\n");
	mms.address[p] = 0;
}

int main() {
	int np1 = my_calloc(1, 1);
	int np2 = my_calloc(1, 2);
	int np3 = my_calloc(1, 3);
	int np4 = my_calloc(1, 4);
	my_free(np1);
	my_free(np4);
	int np5 = my_calloc(1, 5);
	return 0;
}