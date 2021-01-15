// Gym 101149I.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

#define NEWLINE std::cin >> '\n';
#define max(x, y) x > y ? x : y
#define loop(n) for(int i = 0; i < n; i++)

typedef std::vector<int> vi;
typedef long long ll;

int main()
{
    int nodes, edges;
    std::cin >> nodes >> edges;
    std::vector<vi> graph(nodes + 1);

    for (int i = 0; i < edges; i++) {
        int u, v; std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    std::pair<int, int> nodeMin;
    nodeMin.first = 0; nodeMin.second = INT_MAX;
            //The node with the minimum number of neighbors
            //(node number, node neighbors).
    for (int i = 1; i < graph.size(); i++) {
        if (graph[i].size() < nodeMin.second) {
            nodeMin.first = i;
            nodeMin.second = graph[i].size();
        }
    }
    vi toBeKeptEmpty;
    toBeKeptEmpty.push_back(nodeMin.first);
    for (int i = 0; i < nodeMin.second; i++)
        toBeKeptEmpty.push_back(graph[nodeMin.first][i]);
    std::sort(toBeKeptEmpty.begin(), toBeKeptEmpty.end());

    std::vector<bool> toPrint(nodes + 1, true);
    for (int i = 0; i < toBeKeptEmpty.size(); i++) {
        toPrint[toBeKeptEmpty[i]] = false;
    }
    for (int i = 1; i < toPrint.size(); i++)
        if (toPrint[i])
            std::cout << "1 ";
        else
            std::cout << "0 ";
}
