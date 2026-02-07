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
    |x-ai| >= k
    a1 a2
    a2 a3
    a3 a4

    (a1 a2 a3 a4) |ai - aj| >= k 
    k <= max(ai-aj)

    6 2 8 4 5
    2 4 5 6 8
    
    2,4  4
    0,6  6
    6,0  6
    2,4  4
    3 3  3

    ans = 3

       1 55 45 100  k = 54
    -> 1 55 100 45
    -> 55 1 100 45
    -> 55 100 1 45
    -> 1 100 55 45
    -> 1 45 55 100

*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(is_sorted(a.begin()+1,a.end())){
        cout << -1 << endl;
        return;
    }
    vector<int> b(n+1);
    b = a;
    sort(b.begin()+1,b.end());
    int ans = inf;
    for(int i = 1; i <= n; i++){
        if(a[i] != b[i]){
            ans = min(ans, max(a[i] - b[1],b[n] - a[i]));
        }
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