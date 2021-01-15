// Triangle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int>& A);

int main()
{
    
}

int solution(std::vector<int>& A) {
    std::sort(A.begin(), A.end());
    for (int i = 0; i + 2 < A.size(); i++) {
        long long ai = A[i];
        if (ai + A[i + 1] > A[i + 2])
            return 1;
    }
    return 0;
}