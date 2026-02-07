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

void solve(){
    int n, h, l; cin >> n >> h >> l;
    int cnt = 0; 
    int cnt1 = 0;  
    int cnt2 = 0;     
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(x <= min(h, l)){
            cnt++;
        }else if(x <= max(h, l)){
            cnt1++;
        }else if(x > max(h,l)){
            cnt2++;
        }
    }
    int ans = (cnt + cnt1) / 2;
    cout << min(ans,cnt) << endl;
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