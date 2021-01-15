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

#define EXTERNAL_FILES 0
#if EXTERNAL_FILES
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif

#define EXTERNAL_OUT 0
#if EXTERNAL_OUT 
ofstream fout("output.txt");
#define cout fout
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

struct book {
	int t;
	bool a;
	bool b;
};

bool leastTime(book b1, book b2) {
	return b1.t < b2.t;
}

int main()
{
	IOS;
	int n, k;
	cin >> n >> k;
	vector<book> books11, books01, books10;
	while (n--) {
		book bk;
		cin >> bk.t >> bk.a >> bk.b;
		if (bk.a && bk.b) books11.push_back(bk);
		else if (bk.a)    books10.push_back(bk);
		else if (bk.b)    books01.push_back(bk);
	}
	sort(books01.begin(), books01.end(), leastTime);
	sort(books10.begin(), books10.end(), leastTime);
	sort(books11.begin(), books11.end(), leastTime);

	int T = 0, bookCount = 0;
	auto it11 = books11.begin(), it01 = books01.begin(),
		it10 = books10.begin();
	for (;;) {
		if (it11 != books11.end() && it01 != books01.end()
			&& it10 != books10.end()) {
			if (it11->t < it01->t + it10->t) {
				T += it11->t;
				it11++;
			}
			else {
				T += it01->t + it10->t;
				it01++; it10++;
			}
			bookCount++;
		}
		else
			break;
		if (it11 == books11.end() &&
			(it01 == books01.end() || it10 == books10.end()))
			break;
		if (bookCount == k) break;
	}
	while (it11 != books11.end()) {
		if (bookCount == k) break;
		T += it11->t;
		bookCount++;
		it11++;
	}
	while (it01 != books01.end() && it10 != books10.end()) {
		if (bookCount == k) break;
		T += it10->t + it01->t;
		bookCount++;
		it10++; it01++;
	}
	if (bookCount < k)
		cout << "-1";
	else
		cout << T;
}