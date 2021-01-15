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
	int n; cin >> n;
	vi A(n);
	loop(n) cin >> A[i];
	int a = 0, b = n - 1;	//The two pointers.
	int aBars = 0, bBars = 0;	//The bars eaten by Alice and Bob, respectively.
	int t = 0;	//The time.
	while (b - a >= 2) {
		if (A[a] < A[b]) {
			t += A[a];
			A[b] -= A[a];
			a++;
			aBars++;
		}
		else if (A[b] < A[a]) {
			t += A[b];
			A[a] -= A[b];
			b--;
			bBars++;
		}
		else {
			a++;
			b--;
			aBars++;
			bBars++;
		}
	}
	if (b - a == 1) {
		aBars++;
		bBars++;
	}
	else if (b - a == 0) {
		aBars++;
	}
	cout << aBars << ' ' << bBars;
}