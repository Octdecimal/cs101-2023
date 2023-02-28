#include <stdio.h>

int main() {
    char a[] = "A3B2C4A9";
    char b;
    int count = 0;
    for(int i=0; i<sizeof(a); i++) {
        if((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z')) {
            b = a[i];
        }
        if(a[i] >= '1' && a[i] <= '9') {
            count = a[i] - '0';
        }
        if(count != 0) {
            for(int j=0; j<count; j++) {
            printf("%c", b);
            }
        }
        count = 0;
    }
    return 0;
}