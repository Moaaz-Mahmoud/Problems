// Dominator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>

int solution(std::vector<int>& A);

int main()
{
    std::vector<int> A = { 3, 4, 5, 3, 3, 4, 2 };
    std::cout << solution(A);
}

int solution(std::vector<int>& A) {
    if (!A.size()) return -1;
    int maxRep = 0, maxRepIdx = 0;
    std::map<int, int> M;
    for (int i = 0; i < A.size(); i++) {
        M[A[i]]++;
        if (M[A[i]] > maxRep) {
            maxRep = M[A[i]];
            maxRepIdx = i;
        }
    }
    double _ = A.size(); _ /= 2;
    if (M[A[maxRepIdx]] > _) return maxRepIdx;
    return -1;
}