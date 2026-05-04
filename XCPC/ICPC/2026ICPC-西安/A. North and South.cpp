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
    int n; cin >> n;
    vector<int> a(n+1);
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum % n != 0){
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    int pos = sum / n;
    vector<int> pre(n+1);
    /*
        2 3 1 4
        2
          1
            0  
              1
    
    */
    
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i-1] + a[i] - pos;
        // cout << "i: " << i << " " << pre[i] << endl;
        if(pre[i] > 0){
            cout << -1 << endl;
            return;
        }
    }
    int last = 0;
    for(int i = 1; i <= n; i += 2){
        int x = abs(pre[i]);
        if(x > last){
            ans += x - last;
        }
        last = x;
    }
    last = 0;
    for(int i = 2; i <= n; i += 2){
        int x = abs(pre[i]);
        if(x > last){
            ans += x - last;
        }
        last = x;       
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