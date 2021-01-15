// PermCheck.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int solution(std::vector<int>& A);

int main()
{
	std::vector<int> A = { 2, 3, 4, 1 };
	std::cout << solution(A);
}

int solution(std::vector<int>& A) {
	std::vector<int> F(A.size() + 1);
	for (int i = 0; i < F.size() && i < A.size(); i++) {
		if (A[i] < F.size()) {
			F[A[i]]++;
			if (F[A[i]] > 1)
				return 0;
		}
		else {
			return 0;
		}
	}
	return 1;
}