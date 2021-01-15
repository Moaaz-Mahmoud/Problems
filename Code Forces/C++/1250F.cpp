// 1250F.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define NEWLINE std::cin >> '\n';
#define loop(n) for(int i = 0; i < n; i++)

typedef std::vector<int> vi;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	int l = sqrt(n);
	while (n % l) l--;
	cout << 2 * (l + (n / l));
}
