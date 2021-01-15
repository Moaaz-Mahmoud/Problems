#include <iostream>
#include <string>
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
#define all(a) a.begin(), a.end()
#define MULTI_TEST int t; cin >> t; while (t--) 
#define INF 1000000000 // One billion

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

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

string binary(int n) {
	string bin;
	while (n) {
		bin += (n % 2 ? '1' : '0');
		n /= 2;
	}
	reverse(bin.begin(), bin.end());
	return bin;
}
bool isPalindrome(string s) {
	for (int i = 0, j = s.size() - 1; i < j; i++, j--)
		if (s[i] != s[j]) return 0;
	return 1;
}
bool isPrime(ll n) {
	if (n <= 1) return false;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}
inline vi sieve(int n) {
	vector<bool> isPrime(n + 1, true);
	for (int i = 2; i <= sqrt(n); i++) {
		if (isPrime[i])
			for (int j = 2 * i; j <= n; j += i) {
				isPrime[j] = false;
			}
	}
	vi primes;
	for (int i = 2; i <= n; i++)
		if (isPrime[i]) primes.push_back(i);
	return primes;
}

inline vi primeFactors(int n) {
	vi factors;
	vi primes = sieve(100000);
	int i = 0;
	while (n != 1 && i < primes.size()) {
		if (n % primes[i] == 0) {
			factors.push_back(primes[i]);
			n /= primes[i];
		}
		else {
			i++;
		}
	}
	return factors;
}

void shift_right(vi& A, int x) {
	int n = A.size();
	x %= n;
	vi B(n);
	for (int i = 0; i < n; i++)
		B[(i + x)%n] = A[i];
	A = B;
}
inline vector<bool> sieveQuery(int n) {
	vector<bool> isPrime(n + 1, true);
	for (int i = 2; i <= sqrt(n); i++) {
		if (isPrime[i])
			for (int j = 2 * i; j <= n; j += i) {
				isPrime[j] = false;
			}
	}
	return isPrime;
}


vi bfs(const vector<vi>& G, int start) {
	vi dist(G.size(), -1);
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int node : G[u]) if (dist[node] == -1) {
			q.push(node);
			dist[node] = dist[u] + 1;
		}
	}
	return dist;
}

int findLast_grt_eq(vi& A, int x) {
	int n = A.size(),
		l = 0, r = n - 1,
		ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (A[mid] <= x)     l = mid + 1, ans = mid;
		else if (A[mid] > x) r = mid - 1;
	}
	return ans;
}





ll n, k;
vi A, B;
ll can(ll m) {
	ll needed = 0;
	for (int i = 0; i < n; i++) {
		ll required = m * B[i];
		ll existing = A[i];
		needed += max(0LL, required - existing);
		if (needed > k) return 0;
	}
	return needed <= k;
}

int main()
{
	IOS;
	cin >> n >> k;
	B.resize(n); loop(n) cin >> B[i];
	A.resize(n); loop(n) cin >> A[i];

	ll l = 0, r = 20 * 1e8 + 1, m;
	ll ans = 0;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (can(m)) ans = m, l = m + 1;
		else        r = m - 1;
	}

	cout << ans;
}
