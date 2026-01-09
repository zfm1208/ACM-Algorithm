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
bool cmp(pair<int,pii> a,pair<int,pii> b){
    if(a.se.fi == b.se.fi) return a.fi < b.fi;
    return a.se.fi > b.se.fi;
}
void solve() {
    int n; cin >> n;
    vector<pair<int,pii>> a(n+1);
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int x,y,c,d; cin >> x >> y >> c >> d;
        if(c==1 && d == 0) {
            cnt++;
            a[i] = {x, {1, i}};
        }
        else if(c==0 && d == 1) a[i] = {y,{0,i}};
        else if(c==1 && d == 1) {
            if(x < y){
                cnt++;
                a[i] = {x,{1,i}};
            }
            else{
                a[i] = {y,{0,i}};
            }
        }
    }
    sort(a.begin()+1,a.end(),cmp);
    cout << cnt << " ";
    for(int i = 1; i <= n; i++){
        if(a[i].se.fi == 1){
            cout << a[i].se.se << " ";
        }
    }
    cout << endl;
    cout << n - cnt << " ";
    for(int i = 1; i <= n; i++){
        if(a[i].se.fi == 0){
            cout << a[i].se.se << " ";
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}
