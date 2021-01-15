// MaxSliceSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int solution(std::vector<int>& A);

int main()
{
	std::vector<int>
		A = { 2, 5, 3, -9, 5, 5, -5, 3 },
		B = { -2, -3, -5, -7, -9, -2 },
		C = { -20000, -1, -5000, -61, -3, -7000 };
	std::cout
		<< solution(A) << '\n'
		<< solution(B) << '\n';
	std::cout
		<< solution(C) << '\n';
}

int solution(std::vector<int>& A) {
	bool nonNeg = false;
	for(int i = 0; i < A.size(); i++)
		if (A[i] >= 0) {
			nonNeg = true;
			break;
		}
	if (!nonNeg) {	//return min
		int min = 2147483647;
		for (int i = 0; i < A.size(); i++)
			if (abs(A[i]) < min) min = abs(A[i]);
		return -min;
	}

	int maxEnding = 0, maxSlice = 0;
	for (int i = 0; i < A.size(); i++) {
		maxEnding = 0 > maxEnding + A[i] ? 0 : maxEnding + A[i];
		maxSlice = maxSlice > maxEnding ? maxSlice : maxEnding;
	}
	return maxSlice;
}