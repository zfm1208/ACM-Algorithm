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
#define i128  __int128_t
void solve(){
    int n,k,m,a,b; 
    cin >> n >> k >> m >> a >> b;
    if(n % m == 0){cout << 0 << endl; return;}
    if(k == 1){
        cout << -1 << endl;
        return;
    }
    i128 temp = n;
    i128 ans = 0;
    while(temp){
        temp /= k;
        ans+=b;
    }
    int mn = ans;
    auto check = [&] (i128 l,i128 r) -> bool {
        i128 op = r / m * m;
        return op >= l;
    };
    i128 qwq = 1;
    for(int i = 0; i <= 128 ; i++){ 
        i128 cost = i * b;
        i128 nn = n;
        nn /= qwq;
        if(nn <= 0) break;
        i128 L,R;
        i128 ovo = 1;
        for(int j = 0; j <= 128; j++){
            i128 cost1 = 0;
            L = nn * ovo;
            R = (nn+1) * ovo - 1;
            if(check(L,R)){
                cost1 = j * a;
                ans = min((i128)ans, (i128)(cost + cost1)); 
                break;
            }
            ovo *= k;
        }
        qwq *= k;  
    }
    cout << min((int)ans,(int)mn) << endl;
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