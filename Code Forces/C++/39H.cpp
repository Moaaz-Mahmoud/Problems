// 39H.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
using namespace std;

#define NEWLINE std::cin >> '\n';
#define max(x, y) x > y ? x : y
#define loop(n) for(int i = 0; i < n; i++)

typedef std::vector<int> vi;
typedef long long ll;

inline string toBasek(int n, int k) {
    string result = "";
    while (n) {
        result += ((n % k) + '0');
        n /= k;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    int k; std::cin >> k;
    for (int i = 1; i <= k-1; i++) {
        for (int j = 1; j <= k-1; j++) {
            cout << toBasek(i * j, k) << ' ';
        }
        cout << '\n';
    }
}
