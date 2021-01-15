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
	int t; cin >> t;
	string s;
	while (t--) {
		cin >> s;
		bool flag = true;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == 'a') {
				if (s[i - 1] != 'z')
					flag = false;
			}
			else if (s[i] - s[i - 1] != 1) flag = false;
		}
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	} //end t
}