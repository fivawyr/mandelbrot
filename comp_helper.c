#include <complex.h>
#include <stdio.h>

int main() {
    double _Complex n =  1 + 3 + I;
    double real_part = creal(n);
    double imaginary_part = cimag(n);
    printf("Your real part is: %f\n", real_part);
    printf("Your imnaginary part is %f\n", imaginary_part);
}
