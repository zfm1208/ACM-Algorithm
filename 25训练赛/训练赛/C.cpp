#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<pii> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    sort(a.begin()+1,a.end());
    priority_queue<int,vector<int>,greater<int>> pq;
    int ans = 0;
    int now = 0,i = 1; 
    while(i <= n || !pq.empty()){
        if(pq.empty() && now < a[i].fi){
            now = a[i].fi;
        }
        while(i <= n && a[i].fi <= now){
            pq.push(a[i].se);
            i++;
        }
        while(!pq.empty() && pq.top() < now){
            pq.pop();
        }
        if(pq.size()){
            pq.pop();
            ans++;
            now++;
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