#include <stdio.h>

int factorial(int n) {
    int result = 1;
    int i; // Loop variable

    // Loop invariant: At the start of each iteration, `result` holds the factorial of `i-1`.
    for (i = 1; i <= n; i++) {
        // Computation: Multiply `result` by `i`.
        result *= i;

        // Validation of loop invariant
        printf("Loop Invariant: At iteration %d, result = %d (factorial of %d)\n", i, result, i - 1);
    }

    return result;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int result = factorial(n);

    printf("Factorial of %d is: %d\n", n, result);

return 0;
}
