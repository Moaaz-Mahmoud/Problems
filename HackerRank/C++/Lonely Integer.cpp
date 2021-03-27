#include <bits/stdc++.h>
using namespace std;

int lonelyinteger(vector<int> A) {
    int ans = 0;
    for(int a : A) ans ^= a;
    return ans;
}
