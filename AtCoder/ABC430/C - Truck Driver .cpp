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
    int n,A,B; cin >> n >> A >> B;
    string s; cin >> s;
    s = " " + s;
    vector<int> pre_a(n+1), pre_b(n+1);
    for(int i = 1; i <= n; i++){
        pre_a[i] = pre_a[i - 1] + (s[i] == 'a');
        pre_b[i] = pre_b[i - 1] + (s[i] == 'b');
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int res1 = -1,res2 = -1;
        int l = i, r = n;
        while(l <= r){
            int mid = (l + r) / 2; 
            if(pre_b[mid] - pre_b[i - 1] < B){
                res1 = mid;  
                l = mid + 1;
            } else {
                r = mid - 1; 
            }
        }
        if(res1 == -1) continue;
        l = i, r = res1;
        while(l <= r){
            int mid = (l + r) / 2;             
            if(pre_a[mid] - pre_a[i - 1] >= A){
                res2 = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if(res2 != -1) ans += (res1 - res2 + 1);
    }
    cout << ans << endl;
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