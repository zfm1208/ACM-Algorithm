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

void solve(){
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n), b(n), diff(n);
    int s1 = 0;
    
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        s1 += a[i];        
        diff[i] = b[i] - a[i];   
    }
    
    sort(diff.rbegin(), diff.rend());
    
    int ans = 0;
    
    if(n == 1){
        ans = b[0]; 
    } else {
  
        int max_c = min(n - 2, m - n);
        max_c = max(0LL, max_c);
        
        int sum1 = s1;
        ans = sum1; 

        for(int c = 1; c <= max_c; c++){
            sum1 += diff[c - 1]; 
            ans = max(ans, sum1);
        }

        if(2 * n - 1 <= m){
            int sum = 0;
            for(int i = 0; i < n; i++) {
                sum += b[i];
            }
            ans = max(ans, sum);
        }
    }
    
    cout << ans << '\n';
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