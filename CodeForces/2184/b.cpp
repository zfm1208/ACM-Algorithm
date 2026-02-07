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

// 漏斗记时s分钟，人每k分钟翻转一次
// 现在问经过m分钟后停止翻转漏斗，m分钟后漏斗中剩余的时间
void solve(){
    int s,k,m; cin >> s >> k >> m;
    int t = m / k; 
    int r = m % k;    
    if(s <= k){
        if(r == 0){
            cout << s << endl;
        }else{
            cout << max(0LL, s - r) << endl;
        }
    }else{
        if(r == 0){
            if(t&1){
                cout << k << endl;
            }else{
                cout << s << endl;
            }
        }else{
            if(t&1){
                cout << k - r << endl;
            }else{
                cout << s - r << endl;
            }            
        }
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