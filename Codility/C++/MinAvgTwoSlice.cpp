// MinAvgTwoSlice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int solution(std::vector<int>& A);

int main()
{
    std::vector<int> A = { 4, 2, 2, -5, 1, 5, 6 , 8 };
    std::cout << solution(A);
}

int solution(std::vector<int>& A) {
    double minVal = 20000000, minIndex = 0;
    for (int i = 0; i < A.size() - 1; i++) {
        double sum = (A[i] + A[i + 1]);
        if ( sum / 2 < minVal ) {
            minIndex = i;
            minVal = sum / 2;
        }
    }
    for (int i = 0; i < A.size() - 2; i++) {
        double sum = (A[i] + A[i + 1] + A[i + 2]);
        if (sum / 3 < minVal) {
            minIndex = i;
            minVal = sum / 3;
        }
    }
    return minIndex;
}