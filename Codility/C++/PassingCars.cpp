// PassingCars.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int solution(std::vector<int>& A);

int main()
{
    
}

int solution(std::vector<int>& A) {
    std::vector<int> P(A.size());
    P[0] = A[0];
    for (int i = 1; i < P.size(); i++)
        P[i] = P[i - 1] + A[i];
    int result = 0;
    for (int i = 0; i < P.size(); i++) {
        if (!A[i]) {
            result += P[P.size() - 1] - P[i];
            if (result > 1000000000)
                return -1;
        }
    }
    return result;
}