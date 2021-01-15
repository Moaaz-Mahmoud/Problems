// Distinct.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>

int solution(std::vector<int>& A);

int main()
{
    
}

int solution(std::vector<int>& A) {
    std::set<int> S;
    for (int i = 0; i < A.size(); i++) {
        S.insert(A[i]);
    }
    return S.size();
}