#include <math.h>
#include <stdio.h>
#include <stdlib.h>

long long multiply(long long, long long, long long);
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: main 'operand1' 'operand' 'n digits'\n");
        return 0;
    }
    long long a = atoi(argv[1]);
    long long b = atoi(argv[2]);
    long long n = atoi(argv[3]);
    long long result = multiply(a, b, n);
    printf("Oprand 1: %lld\n", a);
    printf("Oprand 2: %lld\n", b);
    printf("Number of digits: %lld\n", n);
    printf("Result of Multiplication: %lld\n", result);
    return 0;
}

long long multiply(long long a, long long b, long long n) {
    if (n == 1) {
        return a * b; // multiplication for 1-digit numbers will be fast already
    }

    long long power = (long long)pow(10, (n + 1) / 2);

    long long value_a_left = a / power;
    long long value_a_right = a % power;

    long long value_b_left = b / power;
    long long value_b_right = b % power;

    long long u = multiply(value_a_left, value_b_left, n / 2);
    long long v = multiply(value_a_right, value_b_right, n / 2);
    long long w = multiply(value_a_left - value_a_right, value_b_left - value_b_right, n / 2);
    long long z = u + v - w;
    long long p = (long long)(pow(10, n) * u) + (long long)(pow(10, (n + 1) / 2) * z) + v;
    return p;
}
