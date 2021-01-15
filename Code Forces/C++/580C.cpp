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
typedef vector<vi> vvi;
typedef set<int> si;
typedef map<string, int> msi;

#include <fstream>
#define MAX_NODES 100000+9

int n, m;
vi cats(MAX_NODES);
vector<bool> visited(MAX_NODES);

inline void bfs(vector<vi>& graph, int node) {
	visited[node] = true;
	deque<int> q;
	for (int i = 0; i < graph[node].size(); i++) {
		if (!visited[graph[node][i]]) {
			q.push_back(graph[node][i]);
			if(cats[graph[node][i]])
				cats[graph[node][i]] += cats[node];
		}
	}
	;
	while (!q.empty()) {
		int u = q.front(); q.pop_front();
		visited[u] = true;
		for (int i : graph[u]) if (!visited[i]) {
			if (cats[i] || cats[u] > m) {
				cats[i] += cats[u];
			}
			q.push_back(i);
		}
	}
}

int main()
{
	std::cin.tie(0);
	std::cin.sync_with_stdio(0);

	cin >> n >> m;
	vector<vi> graph(MAX_NODES);

	for (int i = 1; i <= n; i++) {
		cin >> cats[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int ans = 0;
	bfs(graph, 1);
	for (int i = 2; i <= n; i++)
		if (cats[i] <= m && graph[i].size() == 1) ans++;
	cout << ans;
}