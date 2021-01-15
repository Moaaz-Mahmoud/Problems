// 765C.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int k, a, b;
    std::cin >> k >> a >> b;
    if (
        (b < k && a % k) ||
        (a < k && b % k)
        )
    {
        std::cout << -1;
        exit(0);
    }
    if (a < k && b < k)
        std::cout << -1;
    else
        std::cout << a / k + b / k;
}
