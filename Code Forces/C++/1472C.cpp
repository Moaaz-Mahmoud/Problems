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
 
string itos(ll n) {
	string s;
	while (n) {
		s += char(n % 10 + 48);
		n /= 10;
	}
	reverse(all(s));
	return s;
}
inline ll fact(ll n) {
	ll fct = 1;
	for (int i = 1; i <= n; i++)
		fct *= i;
	return fct;
}
ll ncr(ll n, ll r) {
	return fact(n) / (fact(n - r) * fact(r));
}
int cnt_dig(int n) {
	int cnt = 0;
	while (n) {
		cnt++;
		n /= 10;
	}
	return cnt;
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
 
 
int n;
vi A(200009);
 
int main()
{
	IOS;
 
#if 1
	int _t_ = 1; cin >> _t_;
	while (_t_--) {
		cin >> n;
		vi B(n + 1);
		for(int i = 1; i <= n; i++) cin >> A[i];
		for (int i = n; i >= 1; i--) {
			if (i + A[i] <= n)
				A[i] += A[i + A[i]];
		}
		int ans = 0;
		loop(n + 1) ans = max(ans, A[i]);
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
