#include <stdio.h>

int fibonacci(int a, int b, int n){
    if (n == 0) {
        return 0;
    }
    
    printf("%d \n", a);
    int c = a+b;
    a = b;
    b = c;

    return fibonacci(a,b,n-1);
}

int main(){

    fibonacci(0,1,6);

    return 0;
}