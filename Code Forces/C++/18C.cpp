// 18C.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

#define NEWLINE std::cin >> '\n';
#define max(x, y) x > y ? x : y
#define loop(n) for(int i = 0; i < n; i++)

typedef std::vector<int> vi;
typedef long long ll;

int main()
{
    int n; std::cin >> n;
    vi A(n);
    for (int i = 0; i < n; i++) 
        std::cin >> A[i];
    for (int i = 1; i < n; i++)
        A[i] += A[i - 1];
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
        if (A[n - 1] - A[i] == A[i]) ans++;
    std::cout << ans;
}
