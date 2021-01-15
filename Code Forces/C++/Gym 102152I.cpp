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

#define NEWLINE cout << '\n'
#define loop(n) for(int i = 0; i < n; i++)
#define INF 1000000000 // One billion

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

inline void freqSort(vi& A) {
	vi F(103), F_(103);
	for (int i : A) {
		if (i < 0)
			F_[-i]++;
		else
			F[i]++;
	}
	int j = 0;
	for (int i = F_.size() - 1; i >= 0; i--) {
		while (F_[i]--)
			A[j++] = -i;
	}
	for (int i = 0; i < F.size(); i++) {
		while (F[i]--)
			A[j++] = i;
	}
}

int main()
{
	std::cin.tie(0);
	std::cin.sync_with_stdio(0);

	int t; cin >> t;
	while (t--) {

		int n, k;
		cin >> n >> k;
		vi A(n);
		loop(n) cin >> A[i];
		freqSort(A);
		int i = 0;
		for (;
			(i < A.size()) && (A[i] < 0) && (i < k);
			i++
			)
		{
			A[i] = -A[i];
		}
		k -= i;
		int minI = 0;
		for (int i = 0; i < A.size(); i++)
			if (abs(A[i]) < A[minI]) minI = i;
		A[minI] *= pow(-1, k);
		int sum = 0;
		for (int j : A) sum += j;
		cout << sum << '\n';

	}
}