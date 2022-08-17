#include <iostream>
#include <string>
#include <sstream>
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
#include <cstring>
#include <chrono>
using namespace std;
using namespace std::chrono;

#define _CRT_SECURE_NO_WARNINGS
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define NEWLINE cout << '\n'
#define loop(n) for(int i = 0; i < n; i++)
#define forn(itr, stt, end) for(int itr = stt; itr < end; i++)
#define all(a) a.begin(), a.end()
#define YN cout << (cn ? "Yes" : "No") << '\n'
#define INF 1000000009
const double PI = acos(-1);


#define EXTERNAL_FILES 0
#if EXTERNAL_FILES
ifstream fin("hello.in");
//ofstream fout("output.txt");
#define cin fin
//#define cout fout
#endif

#define MEASURE_TIME 0

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpll;
typedef priority_queue<int, vi, greater<int>> minheap;


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
inline vector<ll> sieve(ll n) {
	vector<bool> isPrime(n + 1, true);
	for (ll i = 2; i * i <= n; i++) {
		if (isPrime[i])
			for (int j = 2 * i; j <= n; j += i) {
				isPrime[j] = false;
			}
	}
	vector<ll> primes;
	for (ll i = 2; i <= n; i++)
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

void shift_right(vll& A, int x) {
	int n = A.size();
	x %= n;
	vll B(n);
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
	vi Sol;
	while (n) {
		Sol.push_back(n % 10);
		n /= 10;
	}
	return Sol;
}
string binary(ll n) {
	string bin;
	while (n) {
		bin += (n % 2LL ? '1' : '0');
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
void trim(string&s){
	int start = 0, end = s.size()-1;
	while(s[start] == ' ' && start < s.size()) start++;
	while(s[end] == ' ' && end >= 0) end--;
	s = s.substr(start, end-start+1);
}

void hashSort(vll& A){
	map<ll, ll> F;
	for(auto a : A) F[a]++;
	ll i = 0;
	for(auto it : F){
		while(it.second--){
			A[i++] = it.first;
		}
	}
}

#define MAXNODES 100009
int bfs(const vector<vi>& G, int start) {
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
	// return dist;
	return maxDist;
}

class DSU{
private:
	int parent[MAXNODES];
	int groupSize[MAXNODES];
	int edgesCount[MAXNODES];
public:
	DSU(){
		for (int i = 0; i < MAXNODES; i++){
			parent[i] = i;
			groupSize[i] = 1;
			edgesCount[i] = 0;
		}
	}

	int findLeader(int i){
		if (parent[i] == i)  return i;

		return parent[i] = findLeader(parent[i]);
	}

	bool sameGroup(int x, int y){
		int leader1 = findLeader(x);
		int leader2 = findLeader(y);

		return leader1 == leader2;
	}

	void merge(int x, int y){
		int leader1 = findLeader(x);
		int leader2 = findLeader(y);

		if (leader1 == leader2){
			edgesCount[leader1]++;
			return;
		}

		if (groupSize[leader1] > groupSize[leader2]){
			parent[leader2] = leader1;
			groupSize[leader1] += groupSize[leader2];
			edgesCount[leader1] += edgesCount[leader2] + 1;
		}
		else{
			parent[leader1] = leader2;
			groupSize[leader2] += groupSize[leader1];
			edgesCount[leader2] += edgesCount[leader1] + 1;
		}
	}

	int getSize(int x){
		int leader = findLeader(x);
		return groupSize[leader];
	}

	int getEdgesCount(int x){
		int leader = findLeader(x);
		return edgesCount[leader];
	}
};

// 1-indexed
template <class T>
class fenwick {
private:
	vector<T> tree;
	int n;
public:
	fenwick(int n) : n(n) { tree.assign(n + 1, 0); }
	T query(int l, int r) { return query(r) - query(l - 1); }
	T query(int r) {
		T s = 0;
		while (r > 0) s += tree[r], r -= (r & (-r));
		return s;
	}
	void update(int i, T v) {
		while (i <= n) tree[i] += v, i += (i & (-i));
	}
};


#define EXTERNAL_OUT 0
#if EXTERNAL_OUT 
ofstream fout("output.txt");
#define cout fout
#endif

#define MAX 1000009
const ll MOD = 998244353;//1e9 + 7;

// ll n, l, r;
// bool can(ll k){
// 	return l <= k && k <= r;
// }


void init(){

}
void solve(){
	
}

int main()
{
	FAST;
	// init();
	int _t_ = 1; //cin >> _t_;
#if MEASURE_TIME
	auto start = high_resolution_clock::now();
#endif
	while (_t_--) solve();
#if MEASURE_TIME
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << duration.count() << endl;
#endif

#if EXTERNAL_OUT || EXTERNAL_FILES
	fout.close();
	system("output.txt");
#endif
}
