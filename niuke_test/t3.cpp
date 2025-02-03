#include   <stdio.h>
int fun(int  x[], int  k) {  
    if(k==0) return (x[0]);
    return  x[0]+fun(x+1, k-1);
}
int main(){  
    int  x[ ]={1,2,3,4,5};
    printf("%d\n", fun(x,3));
}