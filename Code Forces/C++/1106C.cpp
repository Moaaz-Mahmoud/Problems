// 1106C.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>

inline void fsort(std::vector<int>& A) {
    std::vector<int> F(pow(10, 4) + 4);
    for (int i = 0; i < A.size(); i++) {
        F[A[i]]++;
    }
    int j = 0;
    for (int i = 0; i < F.size(); i++) {
        while (F[i]) {
            A[j++] = i;
            F[i]--;
        }
    }
}

int main()
{
    long long n, ans = 0;
    std::cin >> n;
    std::vector<int> A(n);
    for (int i = 0; i < A.size(); i++)
        std::cin >> A[i];
    fsort(A);
    for (int i = 0; i <= (n / 2) - 1; i++) {
        ans += pow((A[i] + A[n-i-1]), 2);
    }
    std::cout << ans;
}
