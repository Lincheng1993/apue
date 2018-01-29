#include <stdio.h>

typedef int Myfunc(int a, int b);

Myfunc myfunc;

int myftw(int , int , Myfunc *);

int main(void){
    int x = 3;
    int y = 4;
    int ret = myftw(&x, &y, &myfunc);
    printf("%d\n", ret);

    return 0;
}

int myfunc(int a, int b){
    return (a < b);
}

int myftw(int a, int b, Myfunc *func){
    return func(a, b);
}