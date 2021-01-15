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

#define EXTERNAL_FILES 1
#if EXTERNAL_FILES
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

int main()
{
	IOS;

	int n, m,        ans = 0,          a, b, c;
	cin >> n >> m;
	vector<vi> corn(n);
	vi rows(n), columns(m);

	//Fill corn.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			corn[i].push_back(a);
		}
	}
	//Fill rows and columns.
	loop(n) {
		int sum = 0;
		for (int j = 0; j < m; j++)
			sum += corn[i][j];
		rows[i] = sum;
	}
	loop(m) {
		int sum = 0;
		for (int j = 0; j < n; j++)
			sum += corn[j][i];
		columns[i] = sum;
	}
	//(Prefix sum)ize rows and columns.
	for (int i = 1; i < rows.size(); i++)
		rows[i] += rows[i - 1];
	for (int i = 1; i < columns.size(); i++) 
		columns[i] += columns[i - 1];

	cin >> a >> b >> c;

	for (int i = 0; i < m - 2; i++) {
		//Locate line 1 after i, line 2 after j.
		for (int j = i + 1; j < m - 1; j++) {
			int 
			sum1 = columns[i],
			sum2 = columns[j] - columns[i],
			sum3 = columns[columns.size() - 1] - columns[j];
			int _ = 0;
			if (a == sum1) {
				_++;
				sum1 = -1;
			}
			else if (a == sum2) {
				_++;
				sum2 = -1;
			}
			else if (a == sum3) {
				_++;
				sum3 = -1;
			}
			if (b == sum1) {
				_++;
				sum1 = -1;
			}
			else if (b == sum2) {
				_++;
				sum2 = -1;
			}
			else if (b == sum3) {
				_++;
				sum3 = -1;
			}
			if (c == sum1) {
				_++;
				sum1 = -1;
			}
			else if (c == sum2) {
				_++;
				sum2 = -1;
			}
			else if (c == sum3) {
				_++;
				sum3 = -1;
			}
			if (_ == 3) ans++;
		}
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			int
				sum1 = rows[i],
				sum2 = rows[j] - rows[i],
				sum3 = rows[rows.size() - 1] - rows[j];
			int _ = 0;
			if (a == sum1) {
				_++;
				sum1 = -1;
			}
			else if (a == sum2) {
				_++;
				sum2 = -1;
			}
			else if (a == sum3) {
				_++;
				sum3 = -1;
			}
			if (b == sum1) {
				_++;
				sum1 = -1;
			}
			else if (b == sum2) {
				_++;
				sum2 = -1;
			}
			else if (b == sum3) {
				_++;
				sum3 = -1;
			}
			if (c == sum1) {
				_++;
				sum1 = -1;
			}
			else if (c == sum2) {
				_++;
				sum2 = -1;
			}
			else if (c == sum3) {
				_++;
				sum3 = -1;
			}
			if (_ == 3) ans++;
		}
	}
	cout << ans;
}