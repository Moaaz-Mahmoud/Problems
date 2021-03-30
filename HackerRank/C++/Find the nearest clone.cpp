#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi bfs(const vector<vi>& G, int start) {
    int distance = 0, maxDist = 0;
    queue<int> q;
    vector<bool> visited(200000, false);
    vi dist(G.size() + 1, -1);
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        visited[u] = true;
        for (int i : G[u]) if (!visited[i]) {
            q.push(i);
            dist[i] = dist[u] + 1;
            maxDist = max(maxDist, dist[i]);
        }
    }
    return dist;
    //return maxDist;
}

vector<string> split_string(string);


int findShortest(int n, vector<int> U, vector<int> V, vector<long> ids, int val) {
    vector<vi> G(n+1);
    for(int i = 0; i < U.size(); i++){
        G[U[i]].push_back(V[i]);
        G[V[i]].push_back(U[i]);
    }
    vi D = bfs(G, 1);
    vi DC;
    for(int i = 0; i < n; i++) if(ids[i] == val){
        DC.push_back(D[i]);
    }
    sort(all(DC));
    int ans = -1;
    for(int i = 0; i+1 < DC.size(); i++) if(DC[i+1] - DC[i] + 1 < ans || ans == -1) 
        ans = DC[i+1] - DC[i] + 1;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
