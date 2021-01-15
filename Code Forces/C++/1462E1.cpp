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
#define INF (1000000000) // One billion
const double PI = acos(-1);
 
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
bool isPalindrome(string& s) {
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
ll lcm(ll a, ll b) {
	return (min(a, b) / gcd(a, b)) * max(a, b);
}
 
void segmentTree_util(vector<ll>& seg, vector<ll>& ps, int start, int l, int r) {
	if (start >= seg.size() || r >= ps.size() || l > r) return;
	if (l == r) {
		seg[start] = ps[r] - (r == 0 ? 0 : ps[r - 1]);
		return;
	}
	seg[start] = (l == 0) ? ps[r] : ps[r] - ps[l - 1];
	segmentTree_util(seg, ps, start + 1, l, (r - l) / 2);
	segmentTree_util(seg, ps, start + 2, (r - l) / 2 + 1, r);
}
vector<ll> segmentTree(vector<ll>& A) {
	int n = A.size();
	vector<ll> ps(n);
	ps[0] = A[0];
	for (int i = 1; i < n; i++)
		ps[i] = A[i] + ps[i - 1];
	vector<ll> seg(n * n);
	loop(seg.size()) seg[i] = -1;
	segmentTree_util(seg, ps, 0, 0, n - 1);
	return seg;
}
string itos(ll n) {
	string s;
	while (n) {
		s += char(n % 10 + 48);
		n /= 10;
	}
	reverse(all(s));
	return s;
}
 
/*
int t; cin >> t;
while(t--) {
	int n; cin >> n;
	vi A(n); loop(n) cin >> A[i];
 
}
*/
 
#define EXTERNAL_OUT 0
#if EXTERNAL_OUT 
ofstream fout("output.txt");
#define cout fout
#endif
 
 
 
int main()
{
	IOS;
#if 1
	int _t_ = 1; cin >> _t_;
	while (_t_--) {
		ll n; cin >> n;
		vi A(n); loop(n) cin >> A[i];
		sort(all(A));
		int i = 0, j = 2;
		ll ans = 0;
		for (;j < n;) {
			while (j < n && A[j] - A[i] < 3) {
				j++;
			}
			j--;
			if (j - i >= 2)
				ans += ll(j-i) * ll(j-i-1LL) / 2LL;
			i++;
			if (i + 2 >= n) break;
		}
		cout << ans << '\n';
	}
 
#endif
 
 
#if 0
	int _t_ = 1; cin >> _t_;
	while (_t_--) {
 
	}
 
#endif
 
 
#if EXTERNAL_OUT
	fout.close();
	system("output.txt");
#endif
}
