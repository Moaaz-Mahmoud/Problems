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

inline void freqSort(vi& A) {
	vi F(3e7 + 9);
	loop(A.size()) F[A[i]]++;
	int j = 0;
	for (int i = 0; i < F.size(); i++) {
		while (F[i]--) {
			A[j++] = i;
		}
	}
}

int main()
{
	IOS;
	int n, m;
	cin >> n >> m;
	map<string, int> quantities;
	vi priceTags(n);
	loop(n) cin >> priceTags[i];
	loop(m) {
		string fruit; cin >> fruit;
		quantities[fruit]++;
	}
	//Prepare the map.
	vi hash_vals(quantities.size());
	int i = 0;
	for (auto it = quantities.begin(); it != quantities.end(); it++)
		hash_vals[i++] = it->second;
	i = hash_vals.size()-1;
	sort(hash_vals.begin(), hash_vals.end());
	for (auto it = quantities.begin(); it != quantities.end(); it++)
		it->second = hash_vals[i--];
	i = 0;

	sort(priceTags.begin(), priceTags.end());
	int ans = 0;
	for (auto it = quantities.begin(); it != quantities.end(); it++)
		ans += it->second * priceTags[i++];
	cout << ans << ' ';

	reverse(priceTags.begin(), priceTags.end());
	ans = i = 0;
	for (auto it = quantities.begin(); it != quantities.end(); it++)
		ans += it->second * priceTags[i++];
	cout << ans;
}