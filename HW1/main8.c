#include <stdio.h>

int main() {
    char a[] = "Hello";
    int len = sizeof(a)/sizeof(char);
    char b[len];
    for(int i=0; i<len; i++) {
        b[i] = a[i];
    }
    printf("a= %s\n", b);
    for(int i=0; i<len-1; i++) {
        a[i] = b[len - 2 - i];
        if(i == 0) {
            a[i] -= 32;
        }
        if(len - 2 - i == 0) {
            a[i] += 32;
        }
    }
    printf("a= %s", a);
    return 0;
}