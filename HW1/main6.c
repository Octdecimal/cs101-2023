#include <stdio.h>
void Rome_change(char c) {
    if(c-'0'== 1){
        printf("I ");
    }else if(c-'0'== 2){
        printf("II ");
    }else if(c-'0'== 3){
        printf("III ");
    }else if(c-'0'== 4){
        printf("IV ");
    }else if(c-'0'== 5){
        printf("V ");
    }else if(c-'0'== 6){
        printf("VI ");
    }else if(c-'0'== 7){
        printf("VII ");
    }else if(c-'0'== 8){
        printf("VIII ");
    }else if(c-'0'== 9){
        printf("IX ");
    }else{
        printf("%c ", c);
    }
}

int main()
{
    char a[] = "81c8g8u168";
    for(int i=0; i<sizeof(a); i++) {
        Rome_change(a[i]);
    }

    return 0;
}
