// 39D.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    int x1, y1, z1,
        x2, y2, z2;
    cin
        >> x1 >> y1 >> z1
        >> x2 >> y2 >> z2;
    if (x1 != x2 &&
        y1 != y2 &&
        z1 != z2
        )
        cout << "NO";
    else
        cout << "YES";
}
