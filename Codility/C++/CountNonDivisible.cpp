vector<int> solution(vector<int>& A) {
	int n = A.size();
	vector<int> F(2 * n + 1); for (int a : A) F[a]++;
	vector<int> Ans(n);

	for (int j = 0; j < n; j++) {
		int a = A[j];
		int divs = 0;
		for (int i = 1; i * i <= a; i++) if (a % i == 0) {
			divs += F[i];
			if (a / i != i) divs += F[a / i];
		}
		Ans[j] = n - divs;
	}
	return Ans;
}
