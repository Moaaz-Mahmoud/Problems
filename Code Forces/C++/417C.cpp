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
	int n, k;
	cin >> n >> k;
	int edges;
	//if (float(n) * float(k) / 2.0 == n * k / 2)
		edges = n * k / 2;
#if 0
	else {
		cout << "-1";
		exit(0);
	}
#endif
	vector<vector<bool>> G(n + 1);
	loop(n + 1) G[i].resize(n + 1);
	vector<ii> ans;
	for (int i = 1; i <= n; i++) {
		int k_ = 0;
		for (int j = 1; j <= n; j++) {
			if (G[i][j]) continue;
			if (j == i)  continue;
			G[j][i] = true;
			ans.push_back({ i, j });
			if (++k_ == k) break;
		}
		if (k_ != k) {
			cout << -1;
			exit(0);
		}
	}
	cout << ans.size() << '\n';
	loop(ans.size())
		cout << ans[i].first << ' ' << ans[i].second << '\n';
}