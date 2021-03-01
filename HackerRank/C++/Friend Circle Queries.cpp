//Fails 3 test cases.

#include <bits/stdc++.h>

using namespace std;

#define MAXNODES 100009
class DSU{
private:
    int parent[MAXNODES];
    int groupSize[MAXNODES];
public:
    DSU(){
        for (int i = 0; i < MAXNODES; i++){
            parent[i] = i;
            groupSize[i] = 1;
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
            return;
        }

        if (groupSize[leader1] > groupSize[leader2]){
            parent[leader2] = leader1;
            groupSize[leader1] += groupSize[leader2];
        }
        else{
            parent[leader1] = leader2;
            groupSize[leader2] += groupSize[leader1];
        }
    }

    int getSize(int x){
        int leader = findLeader(x);
        return groupSize[leader];
    }
    
};




// Complete the maxCircle function below.
vector<int> maxCircle(vector<vector<int>> queries) {
    map<int, int> NodeNum;
    int cnt = 1;
    for(auto& q : queries){
        if(NodeNum[q[0]] == 0) NodeNum[q[0]] = cnt++;
        if(NodeNum[q[1]] == 0) NodeNum[q[1]] = cnt++;
    }
    
    vector<int> ans(queries.size());
    DSU G;
    int mxSize = 1, idx = 0;
    for(auto& q : queries){
        G.merge(NodeNum[q[0]], NodeNum[q[1]]);
        if(G.getSize(NodeNum[q[0]]) > mxSize) mxSize = G.getSize(NodeNum[q[0]]);
        ans[idx++] = mxSize;
    }
    return ans;
}
