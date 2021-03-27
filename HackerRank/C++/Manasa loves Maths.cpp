#include <bits/stdc++.h>
#define loop(n) for(int i = 0; i < n; i++)
#define forn(itr, stt, end) for(int itr = stt; itr < end; i++)
#define all(a) a.begin(), a.end()
#define YN cout << (can ? "Yes" : "No") << '\n'
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

string itos(ll n) {
    string s;
    while (n) {
        s += char(n % 10 + 48);
        n /= 10;
    }
    reverse(all(s));
    return s;
}

string solve(string n) {
    if(n.size() == 1) return n == "0" || n == "8" ? "YES" : "NO";
    if(n.size() == 2){
        string n_rev = n; reverse(all(n_rev));
        return stoi(n)%8==0 || stoi(n_rev)%8 == 0 ? "YES" : "NO";
    }
    
    vi F(10);
    for(char d : n) F[d-'0']++;
    for(int mul = 0; mul < 1000; mul += 8){
        string mul_s = itos(mul);
        while(mul_s.size() < 3) mul_s = "0" + mul_s;
        vi F_(10); for(char d_ : mul_s) F_[d_-'0']++;
        
        bool can = 1;
        for(int i = 0; i < 10; i++)
            if(F_[i] > F[i]) can = 0;
        if(can) return "YES";
    }
    return "NO";
}
