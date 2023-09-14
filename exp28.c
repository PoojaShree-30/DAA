#include <stdio.h>

int binomialCoeff(int n, int k);

void printPascal(int n) {
    for (int line = 0; line < n; line++) {
        for (int i = 0; i <= line; i++)
            printf("%d ", binomialCoeff(line, i));
        printf("\n");
    }
}

int binomialCoeff(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}
