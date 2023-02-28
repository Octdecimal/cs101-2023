#include <stdio.h>
void change (char str[]) {
    char a[] = "00";
    int temp = 0, carry = 0;
    for(int i=0; i<8; i++) {
        temp = 2 * temp + (str[i] - '0');
        if(i==3 || i==7) {
            if(temp>9) {
                a[carry] = temp - 10 + 65;
            } else {
                a[carry] = temp + '0';
            }
            temp = 0;
            carry += 1;
        }
    }
    printf("%s\n", a);
}

int main() {
    char a[] = "10001111";
    char b[] = "10011110";
    change(a);
    change(b);
    return 0;
}