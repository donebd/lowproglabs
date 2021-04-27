# 1 "Horner.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "Horner.c"
# 1 "Horner.h" 1



double horner(double arr[], int n, double x);
# 2 "Horner.c" 2

double horner(double arr[], int n, double x){
    int i;
    if (n < 2) {
        if (n == 1) return arr[0];
        return 0;
    }
    double fx = arr[0]*x + arr[1];
    for(i=2; i<n; i++) {
        fx *= x;
        fx += arr[i];
    }
    return fx;
}
