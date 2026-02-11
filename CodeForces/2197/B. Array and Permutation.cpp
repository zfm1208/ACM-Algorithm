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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
/*
    一个排列p
    一个目标数组a
    对p进行操作
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1),p(n+1);
    rep(i,1,n) cin >> p[i]; 
    rep(i,1,n) cin >> a[i];
    map<int,vector<int>> mp;
    for(int i = 1; i <= n; i++){
        mp[a[i]].pb(i);
    }
    for(auto [x,arr]: mp){
        if(arr.size() == 1) continue;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - arr[i-1] != 1){
                cout << "NO" << endl;
                return;
            }
        }
    }
    stack<int> st;
    map<int,int> cnt;
    for(int i = 1; i <= n; i++){
        if(cnt[a[i]] == 0){
            st.push(a[i]);
        }
        cnt[a[i]]++;
    }
    int r = n;
    while(st.size()){
        int op = st.top();
        while(r >= 1 && p[r] != op){
            r--;
        }
        if(p[r] == op){
            st.pop();
        }else if(r < 1){
            break;
        }
    }
    if(st.size()){
        cout << "NO" << endl;
    }else{
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