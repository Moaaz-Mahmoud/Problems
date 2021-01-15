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

inline vi sieve(int n) {
	vector<bool> isPrime(n + 1, true);
	for (int i = 2; i * i <= n; i++) {
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
vector<int> solution(int N, vector<int> & P, vector<int> & Q) {
	int M = P.size();
	vi primesN = sieve(N);
	vector<int> semiPrimes_util(N+1);
	for (int i = 0; i < primesN.size(); i++) {
		for (int j = 0; j < primesN.size(); j++) {
			if (primesN[i] * primesN[j] > N)
				break;
			semiPrimes_util[primesN[i] * primesN[j]] = 1;
		}
	}
	for (int i = 1; i < semiPrimes_util.size(); i++)
		semiPrimes_util[i] += semiPrimes_util[i - 1];
	vector<int> queries(M);
	for (int i = 0; i < M; i++)
		queries[i] = semiPrimes_util[Q[i]] - semiPrimes_util[P[i] - 1];
	return queries;
}

int main()
{
	IOS;
	vi 
		P = {1, 4, 16}
		, Q = {26, 10, 20}
		;

	vi ans = solution(26, P, Q);
	loop(ans.size()) cout << ans[i] << ' ';
}
