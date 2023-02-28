#include <stdio.h>
int changeCharToDecimal(char str[], int size) {
    int dec = 0;
    int index = 0;
    for(int i=0; i<size; i++) {
        if(str[i] == '\0') {
            break;
        } else if(str[i] == '-' && str[i+1] >= '1' && str[i+1] <= '9') {
            i += 1;
            index = 1;
            dec = dec * 10 + (str[i] - '0');
        } else if(str[i] >= '1' && str[i] <= '9') {
            dec = dec * 10 + (str[i] - '0');
        }
    }
    if(index == 1) {
        dec = 0 - dec;
    }
    return dec;
}

int main() {
    char a[] = "-99acbc";
    char b[] = "99acbc";
    char c[] = "ac-99bc";
    printf("%d\n", changeCharToDecimal(a, sizeof(a)));
    printf("%d\n", changeCharToDecimal(b, sizeof(b)));
    printf("%d\n", changeCharToDecimal(c, sizeof(c)));
    return 0;
}