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
typedef vector<long long> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define MAX 100000 + 9
vi gold(MAX);
vector<bool> visited(MAX);

ll dfs(const vector<vi> &G, ll node) {
	ll ans = 1e9 + 9;
	stack<int> s;
	s.push(node);
	visited[node] = true;
	while (!s.empty()) {
		ll u = s.top(); s.pop();
		ans = min(ans, gold[u]);
		for (ll i : G[u]) if (!visited[i]) {
			visited[i] = true;
			s.push(i);
		}
	}
	return ans;
}

int main()
{
	IOS;
	ll n, m;
	cin >> n >> m;
	vector<vi> G(n + 1);

	for (ll i = 1; i < G.size(); i++) {
		cin >> gold[i];
	}
	loop(m) {
		ll u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ll sum = 0;
	for (ll i = 1; i < G.size(); i++) if (!visited[i]) {
		sum += dfs(G, i);
	}
	cout << sum;
}