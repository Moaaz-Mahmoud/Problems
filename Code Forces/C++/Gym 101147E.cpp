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
#if 0
ifstream fin("jumping.txt");
#define cin fin;
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

vi bfs(const vector<vi> & G, int start) {
	int n = G.size();
	vi dist(n, -1);
	dist[start] = 0;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int u = q.front(); q.pop();
		int cost = dist[u];
		for (int i : G[u]) if(dist[i] == -1) {
			q.push(i);
			dist[i] = cost + 1;
		}
	}
	return dist;
}


int main()
{
	//IOS;
	freopen("jumping.in", "r", stdin);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<vi> G(n + 1);
		vi constants(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> constants[i];
		//Construct the graph.
		for (int node = 1; node <= n; node++) {
			if (node + constants[node] < G.size())
				G[node + constants[node]].push_back(node);
			if (node - constants[node] >= 0)
				G[node - constants[node]].push_back(node);
		}
		vi distances = bfs(G, G.size() - 1);
		for (int i = 1; i <= n; i++)
			cout << distances[i] << '\n';
	}
}
