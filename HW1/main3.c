#include <stdio.h>

int main() {
    char a[] = "ABCabcABC";
    int shift = 4;
    printf("Origin string: %s\nshift: %d\nNew string: ", a, shift);
    for(int i=shift; i<(sizeof(a) + shift); i++) {
        if(i>=sizeof(a)) {
            printf("%c", a[i - sizeof(a)]);
        } else {
            printf("%c", a[i]);
        }
    }
    return 0;
}