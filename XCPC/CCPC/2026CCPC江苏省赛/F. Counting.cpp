#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define lowbit(x) x & (-x)
#define endl '\n'
const int N = 1e6 + 10, mod = 1e9 + 7, inf = 1e18 + 5;

void solve()
{
    int n;cin >> n;
    vector<int> b(n+1);
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    sort(b.begin()+1,b.end());
    int mex = 0;
    int mx = 0;
    for(int i = 1; i <= n; i++){
        if(b[i] == mex) {
            mex++;
        }
        mx = max(mx, b[i]);
    }
    if(mx > mex){
        cout << mex + 1 << endl;
        return;
    }
    unordered_map<int,int> mp;
    for(int i = 1; i <= n; i++){
        mp[b[i]]++;
    }
    int mn = inf;
    for(int i = 0; i < mex; i++){
        mn = min(mn, mp[i]);
    }
    int ans = (mex) * (mn) +1;
    for(int i = 0; i < mex; i++){
        mp[i] -= mn;
    }
    for(int i = 0; i < mex; i++){
        if(mp[i]) ans++;
        else break;
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}