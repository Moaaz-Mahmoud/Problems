// MaxProductOfThree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int>& A);

int main()
{
    std::vector<int> A = { 2, 3, 4, -1 };
    std::cout << solution(A);
}

#include <algorithm>
int solution(std::vector<int>& A) {
    sort(A.begin(), A.end());
    const unsigned int N = A.size();
    return std::max(A[N - 1] * A[0] * A[1], A[N - 1] * A[N - 2] * A[N - 3]);
}