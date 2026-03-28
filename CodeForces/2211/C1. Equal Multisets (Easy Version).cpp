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
    int n,k; cin >> n >> k;
    vector<int>a(n+1),b(n+1);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    if(k < n - k + 1){
        for(int i = 1; i <= n; i++){
            if(b[i] != -1 && b[i] != a[i]){
                cout << "NO"<< endl;
                return;
            }
        }
        cout << "YES"<< endl;
    }else{
        // [n - k + 1,  k]
        map<int,int>mp;
        for(int i = n - k + 1; i <= k; i++){
            mp[a[i]]++;
        }
        for(int i = n - k + 1; i <= k; i++){
            if(b[i] == -1) continue;
            if(mp[b[i]] == 0){
                cout << "NO"<< endl;
                return;
            }
            mp[b[i]]--;
        }
        for(int i = 1; i < n - k + 1; i++){
            if(b[i] == -1) continue;
            if(b[i] != a[i]) {
                cout << "NO"<< endl;
                return;                
            }
        }
        for(int i = k + 1; i <= n; i++){
            if(b[i] == -1) continue;
            if(b[i] != a[i]) {
                cout << "NO"<< endl;
                return;                
            }
        }
        cout << "YES" << endl;
    }
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