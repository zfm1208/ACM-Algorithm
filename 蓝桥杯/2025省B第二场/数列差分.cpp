#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve(){
    int n; cin >> n;
    vector<int> a(n+1),b(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    sort(a.begin()+1,a.end());
    sort(b.begin()+1,b.end());
    int ans = 0;
    int l = 1;
    for(int i = 1; i <= n;){
        if(l> n) break;
        if(l <= n && b[i] < a[l]){
            l++;
            i++;
        }else{
            l++;
            ans++;
        }
    }
    cout << ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}