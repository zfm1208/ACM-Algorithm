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
const int N = 1e6, mod = 998244353, inf = 1e18 + 5;
/*
    l ^ (l+1) ^ (l+2) ^ (l+3) ^ ... ^ r
    = pre(r) ^ pre[l-1]
    = 0
    pre[r] == pre[l-1]
    (1 <= L < x) (x <= R <= n)

*/
void solve(){
    int n,x; cin >> n >> x;
    // vector<int> pre(n+1);
    // for(int i = 1; i <= n; i++){
    //     pre[i] = pre[i-1] ^ i;
    // }
    // for(int i = 0; i <= n; i++){
    //     cout << "i: " << i << " " << pre[i] << endl;
    // }
    // cout << endl;
    // for(int i = 0; i <= n; i++){
    //     for(int j = i+1; j <= n; j++){
    //         if(pre[i] == pre[j]){
    //             cout << "pre: " << pre[i] << endl;
    //             cout << "i , j : " <<  i << " " << j << " " << endl;
    //         }
    //     }
    // }
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    if(x < 4){
        int cnt0 = 1;  
        int cnt1 = 0;                
        if(x == 1) cnt1 = 0;
        else cnt1 = 1;
        int cnt3 = 0;
        if(n < 3) cnt3 = 0;
        else cnt3 = (n - 3) / 4 + 1;
        cnt3 %= mod;
        int cnt11 = (n - 1) / 4 + 1 - cnt1; 
        cnt11 %= mod;
        // cout << cnt0 << " " << cnt3 << endl;
        int ans = (cnt0 * cnt3 % mod + cnt1 * cnt11 % mod) % mod;
        cout << ans << endl;  
        return;      
    }
    int cnt3 = 0;
    int cnt11 = 0;     
    int cnt0 = x/4 + 1;
    cnt0 %= mod; 
    int cnt1 = (x - 1 - 1) / 4 + 1;
    cnt1 %= mod;
    int op = (n - 3) / 4 + 1;
    if(n >= 3) cnt3 = op - (cnt0 - 1); 
    else{
        cnt3 = 1 - cnt0;
    }
    cnt3 %= mod;
    cnt11 = (n - 1) / 4 + 1 - cnt1;
    cnt11 %= mod;
    int ans = (cnt0 * cnt3 % mod + cnt1 * cnt11 % mod) % mod;
    cout << ans << endl;
}
/* 
i: 0 0   = i
i: 1 1   = 1
i: 2 3   = i+1
i: 3 0   = 0

i: 4 4    
i: 5 1    
i: 6 7    
i: 7 0
 
i: 8 8   = i
i: 9 1   = 1
i: 10 11 = i+1
i: 11 0  = 0

i: 12 12
i: 13 1
i: 14 15
i: 15 0

i: 16 16
i: 17 1
i: 18 19
i: 19 0
i: 20 20

pre: 0
i , j : 0 3 
pre: 0
i , j : 0 7 
pre: 0
i , j : 0 11     [0,3]
pre: 0
i , j : 0 15     [0,3]
pre: 0
i , j : 0 19 
pre: 1
i , j : 1 5   [1,1]
pre: 1
i , j : 1 9   [1,1]
pre: 1
i , j : 1 13 
pre: 1
i , j : 1 17 
pre: 0
i , j : 3 7 
pre: 0
i , j : 3 11 
pre: 0
i , j : 3 15 
pre: 0
i , j : 3 19 
pre: 1
i , j : 5 9   [1,1]
pre: 1
i , j : 5 13 
pre: 1
i , j : 5 17 
pre: 0
i , j : 7 11 
pre: 0
i , j : 7 15 
pre: 0
i , j : 7 19 
pre: 1
i , j : 9 13 
pre: 1
i , j : 9 17 
pre: 0
i , j : 11 15 
pre: 0
i , j : 11 19 
pre: 1
i , j : 13 17 
pre: 0
i , j : 15 19 
*/
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
     cin >> T;
    while(T--)
        solve();
    return 0;
}