#pragma once
#include <iostream>

long long GenNum() {
    long long i, j,  a, n = 99999, k = 0;
    std::cout << "Enter random number from 0 to 8,362: ";
    std::cin >> a;

    if (a > 8362) {
        std::cout << "Error";
        exit(1);
    }

    long long* num = new long long[n + 1];
    for (i = 0; i < n + 1; i++) num[i] = i;

    for (i = 2; i < 10000; i++) if (num[i] != 0) 
        for (j = i; j < n + 1; j += i) num[j] = 0;

    for (int i = 10000; i < n + 1; i++) {
        if (num[i] != 0) {
            if (k == a) a = num[i];
            for (j = i; j < n + 1; j += i) num[j] = 0;
            k++;
        }
    }
    return a;
}

long long Degree(long long fun) {
    int i, j;
    long long* num = new  long long[100];                   //костыль?
    for (i = 0; i < 100; i++) num[i] = i;

    for (i = 2; i < 100; i++) {
        if (num[i] != 0) {
            if ((fun % num[i] != 0) & (num[i] > 3)) {
                return num[i];
                break;
            }
            for (j = i; j < 100; j += i) num[j] = 0;
        }
    }
}

long long Num(long long fun, long long n) {
    for (long long i = 1; i < fun; i++) {
        if ((fun * i + 1) % n == 0) {
            return ((fun * i + 1) / n);
            break;
        }
    }
}

long long Encrypt(long long d, long long n, long long k) {
    long long  a = 1, msg;

    std::cout << "Enter your num < " << d << ": ";
    std::cin >> msg;

    if (msg > d) {
        std::cout << "Error";
        exit(1);
    }

    for (int i = 0; i < n; i++) a = msg * (a % k);
    return a % k;
}

long long Decrypt(long long c, long long d, long long k) {
    long long a = 1, i;
    for (i = 0; i < d; i++) {
        a = a * c;
        if (a > k) a = a % k;
    }
    return a % k;
}
