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
#include <fstream>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define NEWLINE cout << '\n'
#define loop(n) for(int i = 0; i < n; i++)
#define INF 1000000000 // 10^9
#define ten5 100000	// 10^5

#define EXTERNAL_FILES 0
#if EXTERNAL_FILES
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif

#define EXTERNAL_OUT 0
#if EXTERNAL_OUT 
ofstream fout("output.txt");
#define cout fout
#endif

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

inline void freqSort(vi& A) {
	vi F(3e7 + 9);
	loop(A.size()) F[A[i]]++;
	int j = 0;
	for (int i = 0; i < F.size(); i++) {
		while (F[i]--) {
			A[j++] = i;
		}
	}
}


int main()
{
	IOS;
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		vi A(n); loop(n) cin >> A[i];
		sort(A.begin(), A.end());
		int teams = 0;
		for (int i = n - 1; i >= 0; i--) {
			int teamVal = A[i];
			for (int k = 2; i >= 1; k++) {
				if (teamVal >= x) break;
				teamVal = A[--i] * k;
			}
			if (teamVal >= x) teams++;
		}
		cout << teams << '\n';
	}
#if EXTERNAL_OUT
	fout.close();
	system("output.txt");
#endif
}