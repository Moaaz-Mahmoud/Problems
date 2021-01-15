#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <iomanip>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define NEWLINE cout << '\n'
#define loop(n) for(int i = 0; i < n; i++)

#define EXTERNAL_FILES 0
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
typedef map<vi, int> msi;

#define EXTERNAL_OUT 0
#if EXTERNAL_OUT 
ofstream fout("output.txt");
#define cout fout
#endif

int main()
{
	IOS;
	string n; cin >> n;
	vi div8;
	int n_ = 0;
	for (int i = min(4, int(n.size())) - 1, j = 0; i >= 0; i--)
		n_ += (n[i] - '0') * pow(10, j++);
	int max_ = min(n_, 1000); max_ + 8 < 1000 ? max_ += 8 : 0;
	for (int i = 0; i * 8 < max_; i++) {
		div8.push_back(i * 8);
	}
	for (int i : div8) {
		vector<char> digits;
		if (i / 100 >= 1) {
			digits.push_back('0' + i / 100);
			digits.push_back('0' + ((i % 100) / 10));
			digits.push_back('0' + i % 10);
		}
		else if (i / 10 >= 1) {
			digits.push_back('0' + i / 10);
			digits.push_back('0' + i % 10);
		}
		else {
			digits.push_back('0' + i);
		}

		if (digits.size() == 1) {
			for (int i = 0; i < n.size(); i++) {
				if (n[i] == digits[0]) {
					cout << "YES\n" << n[i];
					exit(0);
				}
			}
		}

		if (digits.size() == 2) {
			bool found1 = false, found2 = false;
			char dig1, dig2;
			int i = 0;
			for (; i < n.size(); i++) {
				if (n[i] == digits[0]) {
					found1 = true;
					dig1 = n[i];
					i++;
					break;
				}
			}
			for (; i < n.size(); i++) {
				if (n[i] == digits[1]) {
					found2 = true;
					dig2 = n[i];
					i++;
					break;
				}
			}
			if (found1 && found2) {
				cout << "YES\n" << dig1 << dig2;
				exit(0);
			}
		}

		if (digits.size() == 3) {
			bool found1 = false, found2 = false, found3 = false;
			char dig1, dig2, dig3;
			int i = 0;
			for (; i < n.size(); i++) {
				if (n[i] == digits[0]) {
					found1 = 1;
					dig1 = n[i];
					i++;
					break;
				}
			}
			for (; i < n.size(); i++) {
				if (n[i] == digits[1]) {
					found2 = 1;
					dig2 = n[i];
					i++;
					break;
				}
			}
			for (; i < n.size(); i++) {
				if (n[i] == digits[2]) {
					found3 = 1;
					dig3 = n[i];
					i++;
					break;
				}
			}
			if (found1 && found2 && found3) {
				cout << "YES\n" << dig1 << dig2 << dig3;
				exit(0);
			}
		};
	}
	cout << "NO";

#if EXTERNAL_OUT
	fout.close();
	system("output.txt");
#endif
}