#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
typedef long long ll;
typedef vector<int> vi;
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
 
 
int main() {
	IOS;
	ll n; cin >> n;
	cout << unsorted_factors(n).size() << '\n';
}
