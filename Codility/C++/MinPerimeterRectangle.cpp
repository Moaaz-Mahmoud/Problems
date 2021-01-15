// MinPerimeterREctangle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

#define NEWLINE std::cin >> '\n';
#define max(x, y) x > y ? x : y

typedef std::vector<int> vi;
typedef long long ll;
//freopen("input.txt", "r", stdin);
//std::cin.tie(0);
//std::cin.sync_with_stdio(0);

inline std::vector<int> factors(int N) {
    std::vector<int> Factors;
    int f = 0, i = 1;
    while (i * i <= N) {
        if (!(N % i)) {
            if (i * i == N) Factors.push_back(i);
            else Factors.push_back(i), Factors.push_back(N / i);
        }
        i++;
    }
    return Factors;
}
int solution(int N) {

    std::vector<int> F = factors(N);
    int _ = sqrt(N);
    if (_ == sqrt(N))
        return 4 * (*(F.end() - 1));
    return 2 * (   (*(F.end() - 1)) + (*(F.end() - 2)));
}

int main()
{
    std::vector<int> B = factors(48);
    for (int i = 0; i < B.size(); i++)
        std::cout << B[i] << ' ';
    std::cout << '\n';
    
    system("pause");
    std::vector<int> A = {30, 25, 42};
    for (int i = 0; i < A.size(); i++) {
        std::cout << A[i] << '\t' << solution(A[i]) << '\n';
    }
}

