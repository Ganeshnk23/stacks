#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void sieve_of_eratosthenes(int limit) {
    bool is_prime[limit+1];
    memset(is_prime, true, sizeof(is_prime));

    is_prime[0] = false;
    is_prime[1] = false;

    int sqrt_limit = sqrt(limit);
int i,j;
    for ( i = 2; i <= sqrt_limit; i++) {
        if (is_prime[i]) {
            for ( j = i*i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    printf("Prime numbers up to %d:\n", limit);
    for ( i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int limit = 100;
    sieve_of_eratosthenes(limit);
    return 0;
}
