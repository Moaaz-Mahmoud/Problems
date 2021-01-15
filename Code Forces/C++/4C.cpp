// 4C.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
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
    std::map<std::string, int> M;
    int n; std::cin >> n;
    std::string name;
    for (int i = 0; i < n; i++) {
        std::cin >> name;
        if (M[name])
            std::cout << name << M[name]++ << '\n';
        else {
            std::cout << "OK\n";
            M[name]++;
        }
    }
}