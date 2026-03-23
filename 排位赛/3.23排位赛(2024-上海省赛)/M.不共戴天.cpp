
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
    n 个点， 我们尽可能构造成举行，类似于

    1 2 3 4
    5 6 7 8
    9 10

    这种，多余的我们可以放到最后一行

    然后贪心策列：
    让 一个人横着跳
    让另一个人竖着跳

    这样的话，两个人相交得地方只有 相同得点(u,v)
    但题目中保证了 不会出现这种情况。

*/
void solve(){
    int n; cin >> n;
    int sq = sqrt(n);
    if(sq * sq != n) sq++;
    int m = n - sq;
    cout << m << endl;
    int k = sq;
    vector<vector<int>> a;
    int st = 1;
    while(st <= n){
        vector<int> ans;
        for(int i = 0; i < k && st <= n; i++){
            ans.pb(st);
            st++;
        }
        a.pb(ans);
    }
    // for(auto& ans: a){
    //     for(int x: ans) cout << x << " ";
    //     cout << endl;
    // }
    vector<pii> ans1,ans2;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[i].size() - 1; j++){
            ans1.pb({a[i][j], a[i][j+1]});
        }
    }
    for(int i = 0; i + 1< a.size(); i++){
        for(int j = 0; j < a[i].size(); j++){
            if(j < a[i+1].size()){
                ans2.pb({a[i][j], a[i+1][j]});
            }
        }
    }
    for(int i = 0; i < m; i++){
        cout << ans1[i].fi << " " << ans1[i].se << endl;
    }
    for(int i = 0; i < m; i++){
        cout << ans2[i].fi << " " << ans2[i].se << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}