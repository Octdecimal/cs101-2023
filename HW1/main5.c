#include <stdio.h>
int findTheGoal (int list[], int len, int i) {
    int goal[i+1];
    for(int x=0; x<i+1; x++) {
        goal[x] = -100;
    }
    for(int x=1; x<=i; x++) {
        for(int y=0; y<len; y++) {
            if(list[y]>goal[x] && x==1) {
                goal[x] = list[y];
            } else if(list[y]>goal[x] && x!=1 && list[y]<goal[x-1]) {
                goal[x] = list[y];
            }
        }
    }
    return goal[i];
}

int main() {
    char a[] = "-9 8 7 6 5 -4 3 -2 1";
    int i = 4;
    int len = sizeof(a)/sizeof(char) - 1;
    int list[len];
    for(int x=0; x<len; x++) {
        list[x] = -100;
    }
    for(int x=0, z=0, index=0, temp=0; x<len+2; x++) {
        if(a[x]=='\0') {
            break;
        }else if(a[x]=='-') {
            index=1;
        }else {
            temp = temp * 10 + (a[x]-'0');
        }
        if(a[x+1]==' ' || a[x+1]=='\0') {
            list[z] = temp;
            temp = 0;
            x += 1;
            if(index == 1) {
                list[z] = 0 - list[z];
                index = 0;
            }
            z += 1;
        }
    }
    printf("%d", findTheGoal(list, len, i));
    return 0;
}