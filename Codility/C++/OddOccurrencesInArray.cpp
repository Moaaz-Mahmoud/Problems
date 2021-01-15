// OddOccurrencesInArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define NEWLINE cout << '\n'
#define loop(n) for(int i = 0; i < n; i++)
#define INF 1000000000 // One billion

int solution(std::vector<int>& A);

int main()
{
    std::vector<int>
        A = { 1, 1, 2, 3, 3 },
        B = { 5, 2, 5, 5, 3, 7, 5, 2, 7, 3, 7 };
    std::cout
        << solution(A) << '\n'
        << solution(B) << '\n';
}

int solution(std::vector<int>& A) {
    int ans = 0;
    for (int i : A) ans ^= i;
    return ans;
}


