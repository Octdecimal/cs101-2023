#include <stdio.h>

int main() {
    char a[] = "AABBBCCCCddd";
    int count = 1;
    for(int i=0; i<sizeof(a); i++) {
        if(a[i] == '\0') {
            continue;
        }
        if(a[i] == a[i+1]) {
            count += 1;
        } else {
                printf("%c%d", a[i], count);
                count = 1;
        }
    }
    return 0;
}