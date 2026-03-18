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

// l <= x*k < x*(k+1) <= r

// l/x <= k <= r/x-1
// l/k <= x <= r/(k+1)    

// x = 1e9
// x*(k+1) - x*(k)  = 1e9
// 如果x很大的话, k就会比较小， 可以枚举 k 
// 因为 x*k <= 1e12

// x = 100
// x*k <= 1e12
// 那么 k 就比较大 可以枚举x
void solve(){
    int l,r; cin >> l >> r;

    int cha = r - l;
    if(cha <= 1e6){ 
        int ans = 1;
        for(int x = 1; x <= 1e6; x++){\
            if(((l + x - 1) / x  + 1) * x <= r){
                ans = max(ans,x);
            }
        }
        cout << ans << endl;
    }else{
        int ans = 1;
        for(int k = 1; k <= 1e6; k++){
            if((l / k ) <=  (r / (k+1))){
                int tp = (l+k-1)/k;
                int tp1 = r/(k+1);
                if(tp <= tp1)
                ans = max(ans, max(tp,tp1));
            }
        }
        cout << ans << endl;
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