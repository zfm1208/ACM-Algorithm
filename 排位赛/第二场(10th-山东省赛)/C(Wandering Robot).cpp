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
    int n,k; cin >> n >> k;
    string s; cin >> s;
    int fx = 0,fy = 0;
    int ans = 0;
    for(auto c: s){
        if(c == 'U'){
            fy++;
        }else if(c == 'D'){
            fy--;
        }else if(c == 'L'){
            fx--;
        }else if(c == 'R'){
            fx++;
        }
        ans = max(ans,abs(fx) + abs(fy));
    }
    fx *= (k-1),fy *= (k-1);
    for(auto c: s){
        if(c == 'U'){
            fy++;
        }else if(c == 'D'){
            fy--;
        }else if(c == 'L'){
            fx--;
        }else if(c == 'R'){
            fx++;
        }
        ans = max(ans,abs(fx) + abs(fy));
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