// Fish.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>

int solution(std::vector<int>& A, std::vector<int>& B) {
    int n = A.size();
    int survivors = 0;
    std::stack<int> down;
    for (int i = 0; i < n; i++) {
        if (B[i] == 1) {
            down.push(A[i]);
        }
        else {
            if (down.empty()) {
                survivors++;
            }
            else {
                while (!down.empty()) {
                    if (A[i] > down.top()) {
                        down.pop();
                    }
                    else
                        break;
                }
                if (down.empty()) {
                    survivors++;
                }
            }
        }
    }
    return survivors + down.size();
}

int main()
{
    std::vector<int>
        A = { 4, 3, 2, 1, 5 },
        B = { 0, 1, 0, 0, 0 };
    std::cout << solution(A, B);
}
