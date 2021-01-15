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
typedef set<int> si;
typedef map<string, int> msi;

int main()
{
	std::cin.tie(0);
	std::cin.sync_with_stdio(0);

	string s; cin >> s;
	string target = "heidi";
	int i = 0, count = 0;
	for (char c : target) {
		for (; i < s.size(); i++) {
			if (s[i] == c) {
				count++;
				break;
			}
		}
	}
	if (count == 5) cout << "YES";
	else            cout << "NO";
}