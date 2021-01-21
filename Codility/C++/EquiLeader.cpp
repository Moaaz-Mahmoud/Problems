#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <cstring>
using namespace std;

const int NO_LEADER = -1000050000;
inline int findLeader(const vector<int>& A) {
	int n = A.size();
	int leader = NO_LEADER;
	stack<int> S;
	for (int a : A) 
		if (S.empty())		   S.push(a);
		else if (a != S.top()) S.pop();
		else				   S.push(a);
	return leader = S.empty() ? leader : S.top();
}
int solution(vector<int>& A) {
	int n = A.size(),
		ld = findLeader(A),
		cntl = 0;
	for (int a : A) cntl += a == ld;

	if (ld == NO_LEADER || cntl <= n / 2.0) return 0;

	int cleft = 0, cright = cntl, ans = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] == ld) 
			cleft++, cright--;
		if (cleft > (i + 1) / 2.0 &&
			cright > (n - i - 1) / 2.0)
			ans++;
	}

	return ans;
}
