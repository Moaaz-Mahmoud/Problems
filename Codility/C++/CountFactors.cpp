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

int main()
{
    int n;
    std::cin >> n;
    std::vector<vi> A(n);
    for (int i = 0; i < n; i++)
        A[i].resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> A[i][j];
        }
    }
    bool good;
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (A[i][j] == 1) continue;
        good = false;
        for (int k = 0; k < n; k++) {
            for (int l = 0; l < n; l++) {
                if (A[i][k] + A[l][j] == A[i][j]) {
                    good = true;
                    goto nextElement;
                }
            }
        }
        if (!good) {
            std::cout << "No";
            exit(0);
        }
    nextElement:;
    }
    }
    std::cout << "Yes";
}