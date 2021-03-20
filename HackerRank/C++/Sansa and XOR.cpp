#include <bits/stdc++.h>
using namespace std;

int sansaXor(vector<int> A) {
    int n = A.size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        int m = i, k = n-i-1;
        long long subs = (m+1LL) * (k+1LL);
        if(subs % 2LL) ans ^= A[i];
    }
    return ans;
}
