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
#define INF 1000000000 // One billion

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
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

int main()
{
	IOS;
	int t; cin >> t;
	while (t--) {
		int ans = 0;
		int n; cin >> n;
		vector<int> A(n); 
		for (int i = 0; i < A.size(); i++)
			cin >> A[i];
		vector<short> F(8015);
		for (int i : A) F[i]++;
		for (int i = 1; i < A.size(); i++)
			A[i] += A[i - 1];
		//OK.
		for (int i = 1; i < A.size(); i++)
			if(1 <= A[i] && A[i] <= n)
			if (F[A[i]])
			{
				ans += F[A[i]];
				F[A[i]] = 0;
			}
		for (int start = 0; start < A.size(); start++) {
			for (int end = start + 2; end < A.size(); end++) {
				if(1 <= A[end] - A[start] && A[end] - A[start] <= n)
				if (F[A[end] - A[start]]) {
					ans += F[A[end] - A[start]];
					F[A[end] - A[start]] = 0;
				}
			}
		}
		if (ans == n) ans = 0;
		cout << ans << '\n';
	}
#if EXTERNAL_OUT
	fout.close();
	system("output.txt");
#endif
}