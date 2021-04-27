#include <stdio.h>
#include "Horner.h"

int main() {
    double array[] = {55, 128.5, -12, 9};
    double x = 2.1;
    int n = sizeof(array)/8;
    double f = horner(array, n, x);
    int i;
    for(i = 0; i < n; i++)
        printf("[%.2f] ", array[i]);
    printf("\nx=%f\nf(x)=%f",x,f);
    return 0;
}
