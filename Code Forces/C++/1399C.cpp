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
#include <string.h>
#include <cstring>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define NEWLINE cout << '\n'
#define loop(n) for(int i = 0; i < n; i++)
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<vi, int> msi;
 
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
inline vi sieve(int n) {
	vector<bool> isPrime(n + 1, true);
	for (int i = 2; i <= sqrt(n); i++) {
		if (isPrime[i])
		for (int j = 2*i; j <= n; j += i) {
			isPrime[j] = false;
		}
	}
	vi primes;
	for (int i = 2; i <= n; i++)
		if (isPrime[i]) primes.push_back(i);
	return primes;
}
 
int main()
{
	IOS;
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vi A(n); loop(n) cin >> A[i];
		sort(A.begin(), A.end());
		map<int, int> M;
		for (int target = 1; target < 103; target++) {
			for (int i = 0, j = n - 1; i < j;) {
				if (A[i] + A[j] == target) {
					M[target]++;
					i++;
					j--;
				}
				else if (A[i] + A[j] < target)
					i++;
				else
					j--;
			}
		}
		
		int ans = 0;
		for (auto it = M.begin(); it != M.end(); it++) {
			ans = max(ans, it->second);
		}
		cout << ans << '\n';
	}
 
 
}
