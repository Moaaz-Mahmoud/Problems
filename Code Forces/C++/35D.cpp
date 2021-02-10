#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <list>
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
#define _CRT_SECURE_NO_WARNINGS
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define NEWLINE cout << '\n'
#define loop(n) for(int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define MULTI_TEST int t; cin >> t; while (t--) 
#define INF (1000000000) // One billion
const double PI = acos(-1);

#define EXTERNAL_FILES 1
#if EXTERNAL_FILES
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<vi, int> mvi;


ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return (a / gcd(a, b)) * b;
}
bool isPrime(ll n) {
	if (n <= 1) return false;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}
inline vector<int> sieve(int n) {
	vector<bool> isPrime(n + 1, true);
	for (int i = 2; i * i <= n; i++) {
		if (isPrime[i])
			for (int j = 2 * i; j <= n; j += i) {
				isPrime[j] = false;
			}
	}
	vector<int> primes;
	for (int i = 2; i <= n; i++)
		if (isPrime[i]) primes.push_back(i);
	return primes;
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
inline vector<ll> primeFactors(ll n) {
	vector<ll> F;
	for (ll i = 2LL; i * i <= n; i++) {
		while (n % i == 0) {
			F.push_back(i);
			n /= i;
		}
	}
	if (n > 1) F.push_back(n);
	return F;
}
inline vector<ll> unsorted_factors(ll n) {
	vector<ll> F;
	ll i = 1;
	for (; i * i < n; i++) {
		if (n % i == 0) {
			F.push_back(i);
			F.push_back(n / i);
		}
	}
	if (i * i == n) F.push_back(i);
	return F;
}

void shift_right(vi& A, int x) {
	int n = A.size();
	x %= n;
	vi B(n);
	for (int i = 0; i < n; i++)
		B[(i + x) % n] = A[i];
	A = B;
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
int cnt_dig(int n) {
	int cnt = 0;
	while (n) {
		cnt++;
		n /= 10;
	}
	return cnt;
}
vi digits(ll n) {
	vi A;
	while (n) {
		A.push_back(n % 10);
		n /= 10;
	}
	return A;
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

#define MAXNODES 200009
vi bfs(const vector<vi>& G, int start) {
	int distance = 0, maxDist = 0;
	queue<int> q;
	vector<bool> visited(200000, false);
	vi dist(G.size() + 1, -1);
	visited[start] = true;
	q.push(start);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		visited[u] = true;
		for (int i : G[u]) if (!visited[i]) {
			q.push(i);
			dist[i] = dist[u] + 1;
			maxDist = max(maxDist, dist[i]);
		}
	}
	return dist;
	//return maxDist;
}
class DSU
{
private:
	int parent[MAXNODES];
	int GroupSize[MAXNODES];
public:
	DSU()
	{
		for (int i = 0; i < MAXNODES; i++)
		{
			parent[i] = i;
			GroupSize[i] = 1;
		}
	}

	int findLeader(int i)
	{
		if (parent[i] == i)  return i;

		return parent[i] = findLeader(parent[i]);
	}

	bool sameGroup(int x, int y)
	{
		int leader1 = findLeader(x);
		int leader2 = findLeader(y);

		return leader1 == leader2;
	}


	void merge(int x, int y)
	{
		int leader1 = findLeader(x);
		int leader2 = findLeader(y);

		if (leader1 == leader2)  return;

		if (GroupSize[leader1] > GroupSize[leader2])
		{
			parent[leader2] = leader1;
			GroupSize[leader1] += GroupSize[leader2];
		}
		else
		{
			parent[leader1] = leader2;
			GroupSize[leader2] += GroupSize[leader1];
		}
	}

	int getSize(int x)
	{
		int leader = findLeader(x);
		return GroupSize[leader];
	}
};

//gap between 2 primes is less than 300 for n <= 10^9
//cout<<fixed<<setprecision(n)<<number - for n digits after decimal
//for all numbers less than 10^9 there are at most 10 distinct prime factors

#define EXTERNAL_OUT 0
#if EXTERNAL_OUT 
ofstream fout("output.txt");
#define cout fout
#endif

#if 1
#define MOD 1000000007
#define MAX 10000007
ll dp[2][5];
enum pos{ IN, OUT };	//Position    IN: at D, OUT: not at D
ll solve(pos p, ll n){
	if(dp[p][n] != -1) {
		return dp[p][n];
	}
	else if(p == IN){	//Standing at D? 
		if(n < 2)  return 0;
		if(n == 2) return 3;
		//Can either go to A, B or C
		return dp[p][n] = 3LL * solve(OUT, n-1LL) % MOD;
	}
	else{
		if(n < 1)  return 0;
		if(n == 1) return 1;
		if(n == 2) return 2;
		return dp[p][n] = (
			(dp[OUT][n-1LL] = 2LL * solve(OUT, n-1LL) % MOD) + 
			(dp[IN][n-1LL] = solve(IN, n-1LL) % MOD)
		) % MOD;
	}
}
#endif


int main()
{
	IOS;

#if 1

	int _t_ = 1; //cin >> _t_;
	while (_t_--) {
		int n, x; cin >> n >> x;
		vi A(n);
		loop(n){
			int a; cin >> a;
			A[i] = (n-i) * a;
		}
		sort(all(A));
		int ans = 0;
		for(int i = 0; i < n; i++){
			x -= A[i];
			if(x >= 0) ans++;
			else       break;
		}
		cout << ans;
	}

#endif

#if 0

#endif


#if EXTERNAL_OUT || EXTERNAL_FILES && 0
	fout.close();
	system("output.txt");
#endif
}
