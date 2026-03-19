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
    int n,l,r; cin >> n >> l >> r;
    string s; cin >> s;
    map<char,vector<int>> mp;
    for(int i = 0; i < n; i++){
        mp[s[i]].pb(i);
    }
    int sum = 0;
    for(auto &[c,arr]: mp){
        for(int i = 0; i < arr.size(); i++){
            int it1 = lower_bound(arr.begin(),arr.end(),arr[i]+l) - arr.begin();
            int it2 = upper_bound(arr.begin(),arr.end(),arr[i]+r) - arr.begin();
            sum += (it2 - it1);
        }
    }
    cout << sum << endl;
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