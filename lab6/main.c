#include <stdio.h>
void mul(int i, int j) {
	printf("%d * %d = %d\t", i, j, i * j);
	if(i == 9 && j == 9) {
		return;
	}else if (j == 9) {
		printf("\n");
		mul(i+1, 1);
	}else {
		mul(i, j+1);
	}
}

int main() {
	mul(1,1);
	return 0;
}