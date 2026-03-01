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
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(is_sorted(a.begin()+1,a.end())){
        cout << "Bob" << endl;
        return;
    }
    auto check = [&](int x) -> int {
        if(x == 1) return 1;
        int ans = -1;
        for(int i = 2; i*i <= x; i++){
            if(x % i == 0){
                if(ans == -1) ans = i;
                else  return -9090;
                while(x % i == 0) x/=i;
            }
        }
        if(x > 1){
            if(ans == -1) return x;
            else return -9090;
        }
        return ans;
    };
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        int x = check(a[i]);
        if(x == -9090){
            cout << "Alice"<< endl;
            return;
        }
        ans.pb(x);
    }
    if(is_sorted(ans.begin(),ans.end())){
        cout << "Bob" << endl;
    }else{
        cout << "Alice" << endl;
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