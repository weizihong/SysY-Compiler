#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;
int primes[100000005];

void sieveOfEratosthenes(int n) {
    int i = 0;
    int j = 0;
    while (i <= n) {
        primes[i] = 1;
        i = i + 1;
    }
    i = 2;
    while (i * i <= n) {
        if (primes[i] == 1) {
            j = i * i;
            while (j <= n) {
                primes[j] = 0;
                j = j + i;
            }
        }
        i = i + 1;
    }
    i = 2;
    while (i <= n) {
        if (primes[i] == 1) {
            count = count + 1;
        }
        i = i + 1;
    }
    printf("%d\n", count);
}

int main() {
    int n = 100000000;
    sieveOfEratosthenes(n);
    return 0;
}
