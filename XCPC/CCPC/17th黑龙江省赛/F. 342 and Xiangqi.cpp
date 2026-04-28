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

void solve(){
    int a,b,x,y;
    cin >> a>>b>>x>>y;
    map<pii,int>mp;
    mp[{1,1}]=0,mp[{2,2}]=0,mp[{3,3}]=0,mp[{4,4}]=0,mp[{5,5}]=0,mp[{6,6}]=0,mp[{7,7}]=0;
    mp[{1,2}]=1;
    mp[{1,3}]=1;
    mp[{1,4}]=2;
    mp[{1,5}]=3;
    mp[{1,6}]=3;
    mp[{1,7}]=4;
    mp[{2,1}]=1;
    mp[{2,3}]=2;
    mp[{2,4}]=1;
    mp[{2,5}]=2;
    mp[{2,6}]=2;
    mp[{2,7}]=3;
    mp[{3,1}]=1;
    mp[{3,2}]=2;
    mp[{3,4}]=1;
    mp[{3,5}]=2;
    mp[{3,6}]=2;
    mp[{3,7}]=3;
    mp[{4,1}]=2;
    mp[{4,2}]=1;
    mp[{4,3}]=1;
    mp[{4,5}]=1;
    mp[{4,6}]=1;
    mp[{4,7}]=2;
    mp[{5,1}]=3;
    mp[{5,2}]=2;
    mp[{5,3}]=2;
    mp[{5,4}]=1;
    mp[{5,6}]=2;
    mp[{5,7}]=1;
    mp[{6,1}]=3;
    mp[{6,2}]=2;
    mp[{6,3}]=2;
    mp[{6,4}]=1;
    mp[{6,5}]=2;
    mp[{6,7}]=1;
    mp[{7,1}]=4;
    mp[{7,2}]=3;
    mp[{7,3}]=3;
    mp[{7,4}]=2;
    mp[{7,6}]=1;
    mp[{7,5}]=1;
    
    int ans=min(mp[{a,x}]+mp[{b,y}],mp[{a,y}]+mp[{b,x}]);
    cout << ans << '\n';
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