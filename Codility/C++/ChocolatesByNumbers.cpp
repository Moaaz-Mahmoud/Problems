typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return (a / gcd(a, b)) * b;
}

int solution(int N, int M) {
    return lcm(N, M) / M;
}
