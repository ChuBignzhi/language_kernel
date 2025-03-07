#include<stdio.h>
int main(){
    int a, b;
    for(a = 1, b = 1; a <= 100; a++){
        if(b >= 20)
            break;
        if(b % 3 == 1){
            b = b + 3;
            continue;
        }
        b = b - 5;
    }
    printf("%d\n" ,a);
    return 0;
}