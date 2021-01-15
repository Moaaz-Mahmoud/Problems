// Gym 102397J.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int n, x, a,  ans = 0;
    cin >> n >> x >> a;
    int current = a;
    while (n > 0) {
        n -= a / x;
        ans++;
    }
    cout << ans;
}

