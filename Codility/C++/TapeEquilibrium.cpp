// Tape equilibrium.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int solution(std::vector<int>& A);

int main()
{
    std::vector<int> A = { 2, 5, 3, 2, -7, 6 };
    std::cout << solution(A);
}

int solution(std::vector<int>& A) {
    long long right, left;
    std::vector<long long> PS(A.size());
    PS[0] = A[0];
    for (int i = 1; i < PS.size(); i++)
        PS[i] = A[i] + PS[i - 1];

    long long result = pow(10, 10);
    for (int i = 0; i <= PS.size() - 2; i++) {
        left = PS[i];
        right = PS[PS.size() - 1] - left;
        if (abs(right - left) < result)
            result = abs(right - left);
    }
    return result;
}