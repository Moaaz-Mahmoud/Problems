// 44C.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int main()
{
    int n, m,      start, end;
    cin >> n >> m;
    vi A(n + 2);
    loop(m) {
        cin >> start >> end;
        A[start]++;
        A[end + 1]--;
    }
    for (int i = 1; i <= n; i++) A[i] += A[i - 1];
    pair<int, int> problem;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (A[i] != 1) {
            problem.first = i;
            problem.second = A[i];
            flag = true;
            break;
        }
    }
    if (flag)
        cout << problem.first << ' ' << problem.second;
    else
        cout << "OK";
}
