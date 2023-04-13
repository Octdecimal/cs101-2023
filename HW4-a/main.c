#include <stdio.h>
#include <time.h>
int count = 1;
void hanoi(FILE* F, int n, char begin, char buffer, char end) {
	if(n == 0) {
		return;
	}
	hanoi(F, n-1, begin, end, buffer);
	time_t t;
	time(&t);
	char Time[64];
	strftime(Time, 64,"%Y %m%d %X", gmtime(&t));
	char text[64];
	sprintf(text ,"%d(%s): palte_%d form %c to %c\n",count, Time, n, begin, end);
	count++;
	fprintf(F, text);
	hanoi(F, n-1, buffer, begin, end);
}

int main() {
	FILE* F = fopen("hanoi.txt", "w+");
	time_t a, b;
	time(&a);
	char Time[64];
	strftime(Time, 64,"%Y %m%d %X", gmtime(&a));
	char text[64];
	sprintf(text, "time of begin: %s\n", Time);
	fprintf(F, text);
	hanoi(F, 20, 'A', 'B', 'C');
	time(&b);
	strftime(Time, 64,"%Y %m%d %X", gmtime(&b));
	sprintf(text, "time of end: %s\n", Time);
	fprintf(F, text);
	printf("the program is end");
	fclose(F);
	return 0;
}
//%Y %m%d %X => Time
//count(Time): nP from .. to ..