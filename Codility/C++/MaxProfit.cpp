#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define loop(n) for(int i = 0; i < n; i++)


typedef long long ll;
typedef vector<int> vi;

int solution(vector<int>& A) {
    if(A.empty()) return 0;
	int n = A.size();
	vi SM(n);
	SM[n - 1] = A[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		SM[i] = max(A[i], SM[i + 1]);
	}
	int ans = -20000000;
	for (int i = 0; i + 1 < n; i++) {
		ans = max(ans, SM[i + 1] - A[i]);
	}
	return max(ans, 0);
}
