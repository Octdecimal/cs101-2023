#include <stdio.h>
void mul(int i, int j) {
	printf("%d * %d = %d\t", i, j, i * j);
	if(i == 9 && j == 9) {
		return;
	}else if (j == 9) {
		i++;
		j = 0;
		printf("\n");
	}
	j++;
	mul(i, j);
}

int main() {
	mul(1,1);
	return 0;
}