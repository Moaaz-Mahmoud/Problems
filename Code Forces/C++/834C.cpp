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
const double PI = acos(-1);
 
#define EXTERNAL_FILES 0
#if EXTERNAL_FILES
ifstream fin("avatar.in");
ofstream fout("avatar.in");
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
 
const int MAXR = 1000005;
ll cbrt (ll x)
{
	ll l = 0, r = MAXR;
	while (l != r) {
		ll m = (l + r + 1) / 2;
		if (m * m * m > x)
			r = m - 1;
		else
			l = m;
	}
	return l;
}
 
int main()
{
	IOS;
 
#if 1
 
	int t = 1; cin >> t;
	int T = 1;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		ll rt = cbrt(a * b);
		ll rta = cbrt(a), rtb = cbrt(b);
		if (
			(rt * rt * rt == a * b) &&
			(a % rt == 0) &&
			(b % rt == 0)
			)
			cout << "yes";
		else
			cout << "no";
		NEWLINE;
		T++;
	}
 
#endif
 
#if EXTERNAL_OUT
	fout.close();
	system("output.txt");
#endif
}
