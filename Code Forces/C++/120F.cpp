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

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

int bfs(const vector<vi>& spider, int start) {
	int distance = 0, maxDist = 0;
	queue<int> q;
	vector<bool> visited(spider.size() + 8, false);
	vi dist(spider.size() + 1);
	visited[start] = true;
	q.push(start);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		visited[u] = true;
		for (int i : spider[u]) if(!visited[i]) {
			q.push(i);
			dist[i] = dist[u] + 1;
			maxDist = max(maxDist, dist[i]);
		}
	}
	return maxDist;
}

#define EGGS 0
#if EGGS
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	#define cin fin
	#define cout fout
#endif


int main()
{
	
	IOS; 
#if 0
	int m; cin >> m;
	vector<vi> graph(m + 1);
	for (int i = 1; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cout << bfs(graph, 1);
	exit(0);
#endif
	

	int n; cin >> n;
	int ans = 0;
	while (n--) {
		int ni, height, maxHeight = -1;
		cin >> ni;
		vector<vi> spider(105);
		for (int i = 1; i < ni; i++) {
			int u, v;
			cin >> u >> v;
			spider[u].push_back(v);
			spider[v].push_back(u);
		}
		for (int node = 1; node <= ni; node++) {
			height = bfs(spider, node);
			maxHeight = max(height, maxHeight);
		}
		ans += maxHeight;
	}//end while
	cout << ans;
}
