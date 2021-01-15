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
 
	bool possible = false;
	vector<vector<char>> A(10);
	loop(10) for (int j = 0; j < 10; j++) {
		char a; cin >> a;
		A[i].push_back(a);
	}
	vi prefixCrosses(12), prefixEmpty(12), zeroVector(12);
 
	//Horizontal.
	loop(10) {
		//Prefix crosses and prefix empty for row i.
		prefixCrosses[0] = A[i][0] == 'X';
		prefixEmpty[0] = A[i][0] == '.';
		for (int j = 1; j < 10; j++) {
			prefixCrosses[j] = prefixCrosses[j - 1] + (A[i][j] == 'X');
			prefixEmpty[j] = prefixEmpty[j - 1] + (A[i][j] == '.');
		}
		//Checking for the first five elements in row i.
		if (prefixCrosses[4] == 4) {
			if (prefixEmpty[4] == 1)
				possible = true;
		}
		//Checking for each 5-element consecutive set in row i.
		for (int j = 5; j < 10; j++) {
			if (prefixCrosses[j] - prefixCrosses[j - 5] == 4) {
				if (prefixEmpty[j] - prefixEmpty[j - 5] == 1)
					possible = true;
			}
		}
	}
	
	//Vertical.
	loop(10) {
		prefixCrosses[0] = A[0][i] == 'X';
		prefixEmpty[0] = A[0][i] == '.';
		for (int j = 1; j < 10; j++) {
			prefixCrosses[j] = prefixCrosses[j - 1] + (A[j][i] == 'X');
			prefixEmpty[j] = prefixEmpty[j - 1] + (A[j][i] == '.');
		}
 
		if (prefixCrosses[4] == 4) {
			if (prefixEmpty[4] == 1)
				possible = true;
		}
 
		for (int j = 5; j < 10; j++) {
			if (prefixCrosses[j] - prefixCrosses[j - 5] == 4) {
				if (prefixEmpty[j] - prefixEmpty[j - 5] == 1)
					possible = true;
			}
		}
	}
 
	//Diagonal 1. ^>
	//1
	for (int i = 4; i <= 9; i++) {
		vector<char> upright(i + 1);
		vi prefixX(i + 1), prefixO(i + 1);
		for (int x = i, y = 0; x >= 0; x--, y++)
			upright[y] = A[x][y];
		prefixX[0] = upright[0] == 'X';
		prefixO[0] = upright[0] == 'O';
		for (int j = 1; j < upright.size(); j++) {
			prefixX[j] = prefixX[j - 1] + (upright[j] == 'X');
			prefixO[j] = prefixO[j - 1] + (upright[j] == 'O');
		}
		if (prefixX[4] == 4 && prefixO[4] == 0)
			possible = true;
		for (int j = 0; j + 5 < prefixX.size(); j++) {
			if (prefixX[j + 5] - prefixX[0] == 4 &&
				prefixO[j + 5] - prefixO[0] == 0)
				possible = true;
		}
	}
	//2
	for (int i = 1; i <= 5; i++) {
		vector<char> upright(10-i);
		vi prefixX(10 - i), prefixO(10 - i);
		int j = 0;
		for (int x = 9, y = i; y <= 9; x--, y++)
			upright[j++] = A[x][y];
		prefixX[0] = upright[0] == 'X';
		prefixO[0] = upright[0] == 'O';
		for (int j = 1; j < upright.size(); j++) {
			prefixX[j] = prefixX[j - 1] + (upright[j] == 'X');
			prefixO[j] = prefixO[j - 1] + (upright[j] == 'O');
		}
		if (prefixX[4] == 4 && prefixO[4] == 0)
			possible = true;
		for (int j = 0; j + 5 < prefixX.size(); j++) {
			if (prefixX[j + 5] - prefixX[0] == 4 &&
				prefixO[j + 5] - prefixO[0] == 0)
				possible = true;
		}
	}
 
 
	//Diagonal 2. <^
	//1
	for (int i = 1; i <= 5; i++) {
		vector<char> upright(10 - i);
		vi prefixX(10 - i), prefixO(10 - i);
		int j = 0;
		for (int x = i, y = 0; x <= 9; x++, y++)
			upright[j++] = A[x][y];
		prefixX[0] = upright[0] == 'X';
		prefixO[0] = upright[0] == 'O';
		for (int j = 1; j < upright.size(); j++) {
			prefixX[j] = prefixX[j - 1] + (upright[j] == 'X');
			prefixO[j] = prefixO[j - 1] + (upright[j] == 'O');
		}
		if (prefixX[4] == 4 && prefixO[4] == 0)
			possible = true;
		for (int j = 0; j + 5 < prefixX.size(); j++) {
			if (prefixX[j + 5] - prefixX[0] == 4 &&
				prefixO[j + 5] - prefixO[0] == 0)
				possible = true;
		}
	}
 
	//2
	for (int i = 0; i <= 5; i++) {
		vector<char> upright(10 - i);
		vi prefixX(10 - i), prefixO(10 - i);
		int j = 0;
		for (int x = 0, y = i; y <= 9; x++, y++)
			upright[j++] = A[x][y];
		prefixX[0] = upright[0] == 'X';
		prefixO[0] = upright[0] == 'O';
		for (int j = 1; j < upright.size(); j++) {
			prefixX[j] = prefixX[j - 1] + (upright[j] == 'X');
			prefixO[j] = prefixO[j - 1] + (upright[j] == 'O');
		}
		if (prefixX[4] == 4 && prefixO[4] == 0)
			possible = true;
		for (int j = 0; j + 5 < prefixX.size(); j++) {
			if (prefixX[j + 5] - prefixX[0] == 4 &&
				prefixO[j + 5] - prefixO[0] == 0)
				possible = true;
		}
	}
 
	cout << (possible ? "YES" : "NO");
}
