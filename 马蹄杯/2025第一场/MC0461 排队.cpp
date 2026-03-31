#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
/*
    这种问题叫做 区间调度 问题
    通常 贪心 + 优先队列 (有“扫描线”的思想)
*/
void solve(){
    int n; cin >> n;
    vector<vector<int>> a(n);
    bool ok = 0;
    for(int i = 1; i <= n; i++){
        int op; cin >> op;
        if(op == 1){ // 前面至少有x人
            int x; cin >> x;
            a[x].pb(n-1);
        }else if(op == 2){ // 前面最多x人
            int x; cin >> x;
            a[0].pb(x);
        }else{  // 前面至少x人，最多y人
            int x,y; cin >> x >> y;
            if(x > y) ok = 1;
            a[x].pb(y);
        }
    }
    if(ok){
        cout << "N" << endl;
        return;        
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int p = 0; p < n; p++){
        for(int r: a[p]) pq.push(r);
        if(pq.empty()) {
            cout << "N" << endl;
            return;
        }
        int mn = pq.top();
        pq.pop();
        if(mn < p){
            cout << "N" << endl;
            return;
        }
    }
    cout << "Y" << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}