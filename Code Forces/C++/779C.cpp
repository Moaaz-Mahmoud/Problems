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

struct product {
	int now;
	int then;
};

bool criterion(product a, product b) {
	return a.now - a.then < b.now - b.then;
}

int main()
{
	IOS;
	int n, k;
	cin >> n >> k;
	vector<product> A(n);
	loop(n) cin >> A[i].now;
	loop(n) cin >> A[i].then;
	sort(A.begin(), A.end(), criterion);
	ll ans = 0;
	int i = 0;
	for(; (i < n) && (i < k || A[i].now < A[i].then); i++)
		ans += A[i].now;
	for (; i < n; i++) ans += A[i].then;
	cout << ans;
}