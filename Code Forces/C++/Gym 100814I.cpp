// Gym 100814I.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

#define NEWLINE std::cin >> '\n';
#define max(x, y) x > y ? x : y

typedef std::vector<int> vi;
typedef long long ll;

inline std::string toBin(int n) {
	std::string bin;
	while (n) {
		if (n % 2) bin += '1';
		else bin += '0';
		n /= 2;
	}
	std::reverse(bin.begin(), bin.end());
	return bin;
}
inline int hamDist(int n, int m) {
	//Convert n and m into binary strings.
	std::string a, b;
	a = toBin(n);
	b = toBin(m);
	//Equalize the sizes by adding zeros in the beginning.
	std::string temp;
	int _ = abs( int(a.size()) - int(b.size()) );
	temp.resize( int(_) );
	for (int i = 0; i < temp.size(); i++)
		temp[i] = '0';
	if (a.size() < b.size())
		a = temp + a;
	else
		b = temp + b;
	//Iterate through the string to count the different digits.
	int result = 0;
	for (int i = 0; i < a.size(); i++) 
		if (a[i] != b[i]) result++;
	return result;
}

int main()
{
	int t,           n;
	vi A;
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		A.resize(n);
		for (int i = 0; i < A.size(); i++)
			std::cin >> A[i];
		int maxHam = 0;
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				maxHam = max(maxHam, hamDist(A[i], A[j]));
		std::cout << maxHam << '\n';
		maxHam = 0;
	}
}
