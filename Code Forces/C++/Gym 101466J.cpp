// Gym 101466J.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

inline void Fsort(vi& A) {
    vi F(3e7 + 9);
    loop(A.size()) F[A[i]]++;
    int j = 0;
    for (int i = 0; i < F.size(); i++) {
        while (F[i]--) {
            A[j++] = i;
        }
    }
}

int main()
{
    int n, m, q; cin >> n >> m >> q;
    vi A(n);
    loop(m) cin >> A[i];
    for (int i = m; i < n; i++) {
        A[i] = (A[i - m] + A[i - m + 1])%int(30000000);
    }
    Fsort(A);
    int b;
    loop(q) {
        cin >> b;
        cout << A[b - 1] << '\n';
    }
}
