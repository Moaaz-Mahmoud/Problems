// MaxCounters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
std::vector<int> solution(int N, std::vector<int>& A);
int main()
{
    std::vector<int> A(7);
    A[0] = 3;
    A[1] = 4;
    A[2] = 4;
    A[3] = 6;
    A[4] = 1;
    A[5] = 4;
    A[6] = 4;
    auto S = solution(5, A);
    for (int i = 0; i < solution(5, A).size(); i++)
        std::cout << S[i] << ' ';
}

std::vector<int> solution(int N, std::vector<int>& A) {
    std::vector<int> counters(N + 1);
    int max = 0, min = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] <= N) {
            if (counters[A[i]] < min)
                counters[A[i]] = min + 1;
            else
                counters[A[i]]++;
            if (counters[A[i]] > max) max = counters[A[i]];
        }
        else {
            min = max;
        }
    }
    for (int i = 0; i < counters.size() - 1; i++)
        counters[i] = counters[i + 1];
    counters.pop_back();
    for (int i = 0; i < counters.size(); i++)
        if (counters[i] < min) counters[i] = min;
    
    return counters;
}