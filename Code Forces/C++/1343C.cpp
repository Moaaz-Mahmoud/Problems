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
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define ___ int _t_; cin >> _t_; while(_t_--){

bool sameSign(int a, int b) {
	return (a > 0 && b > 0) || (a < 0 && b < 0);
}

int main()
{
	IOS; ___
	int n; cin >> n;
	vi A(n); loop(n) cin >> A[i];
	ll sum = 0, m = A[0];
	for (int i = 1; i < n; i++) {
		if (!sameSign(A[i], A[i - 1])) {
			sum += m;
			m = A[i];
		}
		m = max(m, A[i]);
	}
	sum += m;
	cout << sum << '\n';
}
#if EXTERNAL_OUT
fout.close();
system("output.txt");
#endif
}