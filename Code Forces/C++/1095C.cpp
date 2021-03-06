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
 
 
vector<vi> dp;
bool can(int p1, int p2, int k) {
	int dif = 0;
	for (int i = 0; i < 24; i++) {
		bool b1 = p1 & (1 << i), b2 = p2 & (1 << i);
		dif += b1 != b2;
	}
	return dif <= k;
}
 
int main()
{
	IOS;
	int n, k;
	cin >> n >> k;
	deque<int> D;
	for (int i = 0; i <= 30; i++)
		if (n & (1 << i)) D.push_back(1 << i);
	
	if (D.size() == k) {
		cout << "YES\n";
		while (!D.empty()) {
			cout << D.front() << ' ';
			D.pop_front();
		}
		exit(0);
	}
	else if (D.size() > k) {
		cout << "NO";
		exit(0);
	}
	
	bool can = 0;
	for (; D.size() < k; ) {
		int back = D.back(); D.pop_back();
		if (back == 1) break;
		if (back / 2 > 1)
			loop(2) D.push_back(back / 2);
		else
			loop(2) D.push_front(back / 2);
	}
	can = D.size() == k;
	if (can) {
		cout << "YES\n";
		while (!D.empty()) {
			cout << D.front() << ' ';
			D.pop_front();
		}
	}
	else {
		cout << "NO";
	}
 
#if EXTERNAL_OUT
	fout.close();
	system("output.txt");
#endif
}
