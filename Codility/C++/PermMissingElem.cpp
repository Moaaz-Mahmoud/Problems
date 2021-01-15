// PermMissingElem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int solution(std::vector<int>& A) {
    int sumN = (A.size() + 1) * (A.size() + 2) / 2;
    int sumA = 0;
    for (int i = 0; i < A.size(); i++)
        sumA += A[i];
    return sumN - sumA;
}

int main()
{
    std::vector<int> A = { 1, 2, 4 };
    std::cout << solution(A);
}
