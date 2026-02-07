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
    int a,b; cin >> a >> b;
    int suma = 0,sumb = 0; 
    int h = 0;     
    while(1){        
        int tp1 = suma,tp2 = sumb;
        if(h&1){
            tp2 += (1ll << h);
        }else{
            tp1 += (1ll << h);
        }
        if((tp1 <= a && tp2 <= b) || (tp1 <= b && tp2 <= a)){
            suma = tp1;
            sumb = tp2;
            h++;
        }else{
            cout << h << endl;
            return;
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