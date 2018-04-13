#include <iostream>
#include <complex.h>
using namespace std;

// #define complex _Complex
int main()
{
    double complex z1 = 1.0 + 3.0 * I;
    double complex z2 = 1.0 - 4.0 * I;

    printf("Working with complex numbers:\n\v");

    printf("Starting values: Z1 = %.2f + %.2fi\tZ2 = %.2f %+.2fi\n",
           creal(z1),
           cimag(z1),
           creal(z2),
           cimag(z2));

    double complex sum = z1 + z2;
    printf("The sum: Z1 + Z2 = %.2f %+.2fi\n", creal(sum), cimag(sum));


    cout << "Hello World!" << endl;
    return 0;
}
