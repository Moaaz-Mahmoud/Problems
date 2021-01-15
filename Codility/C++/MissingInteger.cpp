// MissingInteger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int solution(std::vector<int>& A);

int main()
{
    std::vector<int> A = { 1, 2, 3 };
    std::cout << solution(A);
}

int solution(std::vector<int>& A) {
    std::vector<int> F(1000005);
    for (int i = 0; i < A.size(); i++)
        if (A[i] > 0)
            F[A[i]]++;
    for (int i = 1; i < F.size(); i++)
        if (!F[i]) {
            return i;
        }
}