//
// Created by zfm25 on 2025/7/17.
//
// O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
// O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int, int>
#define int long long
#define ld long double
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
double pi = acos(-1);
const int mod1 = 1e9 + 7, mod2 = 998244353, inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
const int inv2 = 5e8 + 4;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(N); // a[i] : 在第i秒有要去第a[i]层的请求
    for (int i = 1; i <= n; i++){
        int t, f;
        cin >> t >> f;
        a[t] = f;
    }
    vector<int> ans(N); // ans[i] : 在第i秒时所在的楼层
    set<int> st;
    int louc = 1;
    int op = 0; // op = 0 : 不动
    // op = 1 : 向上
    // op = -1: 向下
    for (int i = 0; i < N; i++){
        ans[i] = louc;
        if(st.find(louc) != st.end()){
            st.erase(louc);
        }
        if(a[i] != 0 && a[i] != louc){
            st.insert(a[i]);
        }
        if(st.size() == 0){
            op = 0;
        }
        else if(op == 0 && st.size() == 1){
            if(*st.begin() < louc){
                op = -1;
            }else{
                op = 1;
            }
        }else if(op == 1){
            if(*st.rbegin() >= louc){
                op = 1;
            }else{
                op = -1;
            }
        }else if(op == -1){
            if(*st.begin() <= louc){
                op = -1;
            }else{
                op = 1;
            }
        }
        louc += op;
    }

    while(q--){
        int x;
        cin >> x;
        cout << ans[x] << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    //    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
