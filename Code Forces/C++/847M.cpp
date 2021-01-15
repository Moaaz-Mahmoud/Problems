// 847M.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
#define loop(n) for(int i = 0; i < n; i++)
#define INF 1000000000 // One billion

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

int main()
{
    int n; cin  >> n;
    vi A(n);
    loop(n) cin >> A[i];

    bool isArithmetic = true;
    int d = A[1] - A[0];
    loop(n - 1) {
        if (A[i + 1] - A[i] != d) {
            isArithmetic = false;
            break;
        }
    }
    if (isArithmetic)
        cout << 2 * A[n - 1] - A[n - 2];
    else
        cout << A[n - 1];
}
