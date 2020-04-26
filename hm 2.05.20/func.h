#pragma once
#include <iostream>

int GenNum() {
    long long a, n = 99999, k = 0;
    std::cout << "Enter random number from 0 to 8,362" << std::endl;
    std::cin >> a;

    int* num = new int[n + 1];
    for (int i = 0; i < n + 1; i++) num[i] = i;

    for (int p = 2; p < 10000; p++) {
        if (num[p] != 0) for (int j = p; j < n + 1; j += p) num[j] = 0;
    }

    for (int p = 10000; p < n + 1; p++) {
        if (num[p] != 0) {
            if (k == a) a = num[p];
            for (int j = p; j < n + 1; j += p) num[j] = 0;
            k++;
        }
    }
    return a;
}

int Degree(long long fun) {
    long long i, j;
    long long* num = new  long long[fun + 1];
    for ( i = 0; i < (fun + 1); i++) num[i] = i;

    for (i = 2; i < (fun + 1); i++) {
        if (num[i] != 0) {
            if ((fun % num[i] != 0) & (num[i] > 3)) {
                return num[i];
                break;
            }
            for (j = i; j < (fun + 1); j += i) num[j] = 0;
        }
    }
}

int Num(unsigned _int32  fun, int n) {
    for (int i = 1; i < fun; i++) {
        if ((fun * i + 1) % n == 0) {
            return ((fun * i + 1) / n);
            break;
        }
    }
}

int Encrypt(unsigned _int32  fun, unsigned _int32  n, unsigned _int32  k) {
    unsigned _int32  a = 1, msg;

    std::cout << "Enter your num < " << fun << std::endl;
    std::cin >> msg;

    for (int i = 0; i < n; i++) a = msg * (a % k);
    return a % k;
}

int Decrypt(unsigned _int32  c, unsigned _int32  d, unsigned _int32 k) {
    long long a = 1;
    for(int i = 0; i < d; i++) {
        a = a * c;
        if (a >= k) {
            a = a % k;
        }
    }
    return a % k;
}
