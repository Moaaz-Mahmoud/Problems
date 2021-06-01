#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'maximizingXor' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER l
 *  2. INTEGER r
 */
 typedef long long ll;

string binary(ll n) {
    string bin;
    while (n) {
        bin += (n % 2LL ? '1' : '0');
        n /= 2;
    }
    reverse(bin.begin(), bin.end());
    return bin;
}
ll maximizingXor(ll l, ll r) {
string bitL = binary(l), bitR = binary(r);
    if(bitL.size() == bitR.size()){
        ll i = 0;
        for(; i < bitL.size(); i++){
            if(bitL[i] != bitR[i]) break;
        }
        ll ans = 0;
        for(ll j = 0; i < bitL.size(); i++, j++){
            ans += (1LL<<j);
        }
        return ans;
    }
    else{
        return (1LL << bitR.size()) - 1;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string r_temp;
    getline(cin, r_temp);

    int r = stoi(ltrim(rtrim(r_temp)));

    int result = maximizingXor(l, r);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
