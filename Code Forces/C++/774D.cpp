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
	int n, l, r;
	cin >> n >> l >> r;
	l--; r--;
	vi A(n); loop(n) cin >> A[i];
	vi B(n); loop(n) cin >> B[i];
	bool truth = 1;
	for (int i = 0; i < l; i++)
		if (A[i] != B[i]) truth = 0;
	for(int i = r+1; i < n; i++)
		if (A[i] != B[i]) truth = 0;
	cout << (truth ? "TRUTH" : "LIE");
}