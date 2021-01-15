// Brackets.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

int solution(std::string& S) {
    std::stack<char> stack;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '(' || S[i] == '[' || S[i] == '{')
            stack.push(S[i]);
        else {
            if (stack.empty()) return 0;
            else {
                if (
                    (stack.top() == '(' && S[i] == ')') ||
                    (stack.top() == '[' && S[i] == ']') ||
                    (stack.top() == '{' && S[i] == '}')
                    )
                    stack.pop();
                else
                    return 0;
            }
        }
    } //end for
    if (stack.empty()) 
        return 1;
    return 0;
}

int main()
{
    std::string s;
    while (true) {
        std::cin >> s;
        std::cout << solution(s) << '\n';
    }
}
