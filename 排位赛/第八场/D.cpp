#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define rep(i,l,r) for(int i = l; i <= r; i++)
const int N = 1e6+9, mod = 1e9+7, inf = 1e18;
int vis[N+10];
int pri[N+10];
int cnt = 0;
void init(){
    vis[1] = 1;
    for(int i = 2; i < N; i++){
        if(!vis[i]){
            pri[cnt++] = i;
        }
        for(int j = 0; j < cnt ; j++){
            if(pri[j] * i > N) break;
            vis[pri[j] * i] = 1;
            if(i % pri[j] == 0) break;
        }
    }
}
void solve(){
    int t,n,k; cin >> t >> n >> k;
    // cout << "NB" << endl;
    // return;
    vector<int> a(n+1);
    iota(a.begin(),a.end(),0);
    vector<int> d(n+1);
    int cn = 1;
    while(1){
        if(cn > n) break;
        vector<int> b;
        b.push_back(-9);
        for(int i = 1; i < a.size(); i++){
            if(i == 1 || vis[i] == 0){
                d[cn] = a[i];
                cn++;
                if(cn == n+1) break;
            }else{
                b.push_back(a[i]);
            }
        }
        if(cn == n+1){
            break;
        }
        a = b;
    }
    // cout << "666" << endl;
    // return;
    if(t == 1){
        for(int i = 1; i <= n; i++){
            if(d[i] == k) {
                cout << i << endl;
            }
        }
    }else{
        cout << d[k] << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    init();
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}