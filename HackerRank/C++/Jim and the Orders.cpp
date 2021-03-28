#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()

struct p{
    int idx, time;
};
bool cmp(p x, p y){
    if(x.time != y.time)
        return x.time < y.time;
    return x.idx < y.idx;
}
vector<int> jimOrders(vector<vector<int>> orders) {
    int n = orders.size();
    vector<p> A(n);
    for(int i = 0; i < n; i++){
        A[i].idx = i+1;
        A[i].time = orders[i][0] + orders[i][1];
    }
    sort(all(A), cmp);
    vector<int> ans(n);
    for(int i = 0; i < n; i++) ans[i] = A[i].idx;
    return ans;
}
