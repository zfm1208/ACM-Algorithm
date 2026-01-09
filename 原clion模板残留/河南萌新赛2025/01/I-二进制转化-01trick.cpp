//
// Created by zfm25 on 2025/7/17.
//
#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;

#define int long long
#define debug(x) cerr << #x" = " << x << '\n';

const i64 N = 2e5 + 10, INF = 1e18 + 10;
const i64 mod = 998244353;

void solve()
{
    int n, l, r;
    string s;
    cin >> n >> s >> l >> r;

    if (s.front() == s.back()) {
        cout << "Yes" << endl;
        return;
    } else if (l == 1 || r == n) {
        cout << "Yes" << endl;
        return;
    }

    cout << "No" << endl;
    return;
}

signed main()
{
    cin.tie(nullptr) -> ios::sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T --) solve();
    return 0;
}
