// Binary gap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int solution(int n) {
    std::string s;
    while (n) {
        s += (n % 2 ? '1' : '0');
        n /= 2;
    }

    int first1 = 0, last1 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            first1 = i;
            break;
        }
    }
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '1') {
            last1 = i;
            break;
        }
    }

    int current = 0, largest = 0;
    for (int i = first1 + 1; i < last1; i++) {
        if (s[i] == '0') {
            current++;
        }
        else {
            if (current > largest)
                largest = current;
            current = 0;
        }
    }
    if (current > largest)
        largest = current;
    return largest;
}

int main()
{
    std::cout
        << solution(1) << '\n'
#if 1
        << solution(2)  << '\n'
        << solution(3)  << '\n'
        << solution(4)  << '\n'
        << solution(5)  << "\n\n"
        << solution(10) << '\n'
        << solution(15) << '\n'
        << solution(21) << '\n'
        << solution(26) << '\n'
        << solution(40) << '\n'
        << solution(137) << '\n';
#endif
}
