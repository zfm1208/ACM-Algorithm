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
    rep(i,1,n) cin >> a[i];
    if(is_sorted(a.begin()+1, a.end())){
        cout << "YES" << endl;
        return;
    }
    vector<int> cun;
    int mx = 0;
    for(int i = 2; i <= n; i++){
        if(a[i] < a[i-1]){
            cun.push_back(i);
            mx = max(mx, a[i-1] - a[i]);
        }
    }
    for(int i = 1, last; i <= n; i++){
        if(i == 1){
            last = a[i];
        }else{
            if(a[i] >= last){
                last = a[i];
            }else{
                if(a[i] + mx >= last){
                    last = a[i] + mx;
                }else{
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
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