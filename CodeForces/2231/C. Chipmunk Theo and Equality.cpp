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
    偶数 / 2
    奇数 + 1

    3 2 4 -> 4 2 4 -> 2 2 2
    1 4 2 -> 2 4 2 -> 2 2 2
    3 6 7 16 8 8 7
    4 4 4 4  4 4 4
    1 2 2 2  1 1 2  

    
    7 -> 8 -> 4 -> 2 -> 1
    9 -> 10 -> 5 -> 6 -> 3 -> 4 -> 2 -> 1
    11 -> 12 -> 6 -> 3 -> 4 -> 2 -> 1
    13 -> 14 -> 7 -> 8 -> 4 -> 2 -> 1
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == a[i-1]) cnt++;
    }
    if(cnt == n-1){
        cout << 0 << endl;
        return;
    }
    // unordered_map<int,int> mp;
    // unordered_map<int,int> bs;
    vector<pii> bs;
    vector<int> mp;
    for(int i = 1; i <= n; i++){
        int cs = 0;
        int tp = a[i];
        while(tp > 1){
            bs.push_back({tp, cs});
            mp.push_back(tp);
            // bs[tp] += cs;
            // mp[tp]++;
            if(tp&1) tp++;
            else tp >>= 1;
            cs++;
        }
        mp.push_back(tp);
        bs.push_back({tp,cs});
        // mp[tp]++;
        // bs[tp] += cs;
        if(a[i] == 1){
            mp.push_back(2);
            bs.push_back({2,1});
            // mp[2]++;
            // bs[2]+=1;
        }
    }
    sort(mp.begin(), mp.end());
    mp.erase(unique(mp.begin(), mp.end()), mp.end());
    vector<int> mp1(mp.size());
    vector<int> bs1(mp.size());
    for(auto&[x, cnt] : bs){
        int it = lower_bound(mp.begin(), mp.end(), x) - mp.begin();
        mp1[it]++;
        bs1[it] += cnt;
    }
    int ans = inf;
    // for(auto&[x, cnt]: mp){
    //     if(cnt == n){
    //         ans = min(ans, bs[x]);
    //     }
    // }
    for(int i = 0; i < mp.size(); i++){
        if(mp1[i] == n){
            ans = min(ans,bs1[i]);
        }
    }
    cout << ans << endl;
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