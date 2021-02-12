#include <bits/stdc++.h>
using namespace std;

#define loop(n) for(int i = 0; i < n; i++)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

ll countComponents(ll n, const vector<vector<ll>> &G) {
  vector<bool> visited(n + 3);
  ll ans = 0;
  for (ll i = 1; i <= n; i++) {
    if (visited[i])
      continue;
    ans++;
    stack<ll> S;
    S.push(i);
    while (!S.empty()) {
      ll u = S.top();
      S.pop();
      for (ll nbr : G[u])
        if (!visited[nbr]) {
          S.push(nbr);
          visited[nbr] = true;
        }
    }
  }
  return ans;
}
long long roadsAndLibraries(ll n, ll c_lib, ll c_road, vector<vector<ll>> cities) {
    if(c_road < c_lib){
        vector<vll> G(n+1);
        for(auto city : cities){
            G[city[0]].push_back(city[1]);
            G[city[1]].push_back(city[0]);
        }
        ll components = countComponents(n, G);
        return components * c_lib + (n - components) * c_road;
    }
    else{
        return c_lib * n;
    }
}

vector<string> split_string(string);



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        ll n = stoi(nmC_libC_road[0]);

        ll m = stoi(nmC_libC_road[1]);

        ll c_lib = stoi(nmC_libC_road[2]);

        ll c_road = stoi(nmC_libC_road[3]);

        vector<vector<ll>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

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

    ll i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
