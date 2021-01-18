#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<vi, int> mvi;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

vector<string> split_string(string);

// Complete the solve function below.
string solve(vector<int> A) {
    for(int a : A)
        if(a == 1) return "YES";
    ll g = A[0];
    for(int i = 1; i < A.size(); i++)
        g = gcd(g, A[i]);
    return g == 1LL ? "YES" : "NO";
}
