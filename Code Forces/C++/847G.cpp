// 847G.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

int main()
{
    int n;
    std::vector<int> rooms(7);
    std::string s;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> s;
        for (int j = 0; j < s.size(); j++)
            rooms[j] += s[j] - '0';
    }
    int ans = 0;
    for (int i = 0; i < rooms.size(); i++)
        if (rooms[i] > ans)
            ans = rooms[i];
    std::cout << ans;
}
