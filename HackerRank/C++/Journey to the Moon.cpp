#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

using namespace std;
typedef long long ll;

#define MAXNODES 200009
class DSU{
private:
    int parent[MAXNODES];
    int groupSize[MAXNODES];
    int edgesCount[MAXNODES];
public:
    DSU(){
        for (int i = 0; i < MAXNODES; i++){
            parent[i] = i;
            groupSize[i] = 1;
            edgesCount[i] = 0;
        }
    }

    int findLeader(int i){
        if (parent[i] == i)  return i;

        return parent[i] = findLeader(parent[i]);
    }

    bool sameGroup(int x, int y){
        int leader1 = findLeader(x);
        int leader2 = findLeader(y);

        return leader1 == leader2;
    }

    void merge(int x, int y){
        int leader1 = findLeader(x);
        int leader2 = findLeader(y);

        if (leader1 == leader2){
            edgesCount[leader1]++;
            return;
        }

        if (groupSize[leader1] > groupSize[leader2]){
            parent[leader2] = leader1;
            groupSize[leader1] += groupSize[leader2];
            edgesCount[leader1] += edgesCount[leader2] + 1;
        }
        else{
            parent[leader1] = leader2;
            groupSize[leader2] += groupSize[leader1];
            edgesCount[leader2] += edgesCount[leader1] + 1;
        }
    }

    int getSize(int x){
        int leader = findLeader(x);
        return groupSize[leader];
    }

    int getEdgesCount(int x){
        int leader = findLeader(x);
        return edgesCount[leader];
    }
};


ll journeyToMoon(int n, vector<vector<int>> astronaut) {
    DSU G;
    map<int, int> nodesInComponent;
    vector<bool> isCovered(n+1);

    for(auto& p : astronaut) 
        G.merge(p[0], p[1]);
    for(int i = 0; i < n; i++)
        nodesInComponent[G.findLeader(i)]++;
    int uncoveredNodes = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++) if(!isCovered[G.findLeader(i)]){
        isCovered[G.findLeader(i)] = true;
        uncoveredNodes += G.getSize(i);
        ans += G.getSize(i) * ll(n - uncoveredNodes);
    }

    return ans;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    ll result = journeyToMoon(n, astronaut);

    fout << result << "\n";

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
