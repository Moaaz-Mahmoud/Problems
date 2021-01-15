// 774C.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
using namespace std;

#define NEWLINE std::cin >> '\n';
#define max(x, y) x > y ? x : y
#define loop(n) for(int i = 0; i < n; i++)

typedef std::vector<int> vi;
typedef long long ll;

int main()
{
    int n; cin >> n;
    if (n == 2) {
        cout << 1;
        exit(0);
    }
    if (n == 3) {
        cout << 7;
        exit(0);
    }
    if (n % 2) {
        cout << 7;
        n -= 3;
        while (n) {
            cout << 1;
            n -= 2;
        }
    }
    else {
        for (int i = 0; i < n / 2; i++)
            cout << 1;
    }
}
