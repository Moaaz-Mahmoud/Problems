// Gym 102397I.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
using namespace std;

int main()
{
    int _; cin >> _;
    map<char, int> M;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        M[s[i]]++;
    int max = -1, min = 10000;
    for (char i = 'a'; i <= 'e'; i++) {
        if (M[i] > max) max = M[i];
        if (M[i] < min) min = M[i];
    }
    cout << min << ' ' << max;
}
