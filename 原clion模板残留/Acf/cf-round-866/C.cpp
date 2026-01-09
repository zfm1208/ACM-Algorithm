//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    int n;cin >> n;
    vector<int>a(n+10);
    set<int>st;
    rep(i,1,n) {
        cin >> a[i];
        st.insert(a[i]);
    }
    int mex=0;
    for(int i=0;;i++){
        if(st.count(i))continue;
        else {mex=i; break;}
    }
    int last=0;
    int pre=0;
    rep(i,1,n){
        if(a[i] == mex+1){
            pre=i;
            break;
        }
    }
    per(i,n,1){
        if(a[i] == mex+1){
            last=i;
            break;
        }
    }
    if(pre==0){
        map<int,int>mp;
        rep(i,1,n) mp[a[i]]++;
        bool flag = false;
        for(auto t:mp){
            if(t.second>=2 || t.first>mex+1)
                flag=true;
        }
        if(flag)cout << "YES\n";
        else cout << "NO\n";
    }
    else{
        for(int i=pre;i<=last;i++)a[i]=mex;
        st.clear();
        rep(i,1,n){
            st.insert(a[i]);
            //cout<<a[i]<<" ";
        }
        //cout << "\n";
        //debug;
        int ok = 0;
        for(int i=0;;i++){
            if(st.count(i))continue;
            else{
                ok=i;
                break;
            }
        }
        if(ok == mex+1)cout<<"Yes\n";
        else cout<<"NO\n";
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
