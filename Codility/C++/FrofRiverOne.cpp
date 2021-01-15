// FrofRiverOne.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>

int solution(int X, std::vector<int>& A);


int main()
{
    std::cout << sizeof(long) << "\n\n\n***********\n";
    std::vector<int> A = { 1, 6, 5, 3, 4, 4, 3, 5, 6, 2, 1, 2, 4 };
    std::cout << solution(6, A);
}

int solution(int X, std::vector<int>& A) {
    if (!A.size())
        return 0;
    int n = 0;
    std::vector<int> F(X + 1);
    for (int i = 0; i < A.size(); i++) {
        F[A[i]]++;
        for (int j = 1; j < F.size(); j++) {
            if (!F[j])
                goto cont;
        }
        return i;
    cont:;
    }
}