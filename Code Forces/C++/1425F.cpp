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
 
#define TEST_GENERATION_MODE 0
#if TEST_GENERATION_MODE
ifstream fin("output.txt");
#define cin fin
#endif
 
 
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
 
 
int n1, n2, k1, k2;
vector<vector<vector<vi>>> dp(109);
int mod_ = 100000000;
int solve(int n1, int n2, int last, int successive) {
	if (last == 1 && successive > k1)
		return 0;
	else if (last == 2 && successive > k2)
		return 0;
	if (n1 == 0 && n2 == 0)
		return 1;
	if (n1 < 0 || n2 < 0)
		return 0;
 
	if (last != -1 && dp[n1][n2][last][successive] != -1) {
		return dp[n1][n2][last][successive];
	}
 
	return dp[n1][n2][last][successive] =
		(solve(n1 - 1, n2, 1, (last == 1 ? successive + 1 : 1)  % mod_) +
		 solve(n1, n2 - 1, 2, (last == 2 ? successive + 1 : 1)) % mod_) % mod_;
}
 
int main()
{
	IOS;
	int n; cin >> n;
	vi A(n + 1);
	int i = 1;
	for(; ; ) {
		int s1, s2, s3;
		cout << "? " << i << " " << i + 1 << endl;
		cin >> s1;
		cout << "? " << i + 1 << " " << i + 2 << endl;
		cin >> s2;
		cout << "? " << i << " " << i + 2 << endl;
		cin >> s3;
		A[i] = s3 - s2;
		A[i + 2] = s3 - s1;
		A[i + 1] = s3 - A[i] - A[i + 2];
		i += 3;
		if (i + 2 > n) break;
	}
	if (n % 3) {
		int s;
		cout << "? " << i - 1 << " " << i << endl;
		cin >> s;
		A[i] = s - A[i - 1];
		if (n % 2 == 2) {
			cout << "? " << i << " " << i + 1 << endl;
			cin >> s;
			A[i + 1] = s - A[i];
		}
	}
	cout << "! "; 
	for (int i = 1; i <= n; i++) cout << A[i] << ' ';
	cout << endl;
 
#if EXTERNAL_OUT
	fout.close();
	system("output.txt");
#endif
}
