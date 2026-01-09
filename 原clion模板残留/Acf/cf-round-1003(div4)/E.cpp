#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
//https://codeforces.com/contest/2065/problem/E
void solve() {
    int n,m,k; cin >> n >> m >> k;
    if(abs(n - m) > k || max(n,m) < k){
        cout << -1 << endl;return;
    }
    if(n <= m){
        for(int i = 1; i <= k ; i++) cout << '1';
        m-=k;
        int p = 1;
        while(m < n){
            cout << '0';
            n--;
            p = 0;
        }
        if(!p){
            while(m--){
                cout << "10";
            }
        }else{
            while(m--){
                cout << "01";
            }
        }
    }else{
        for(int i = 1; i <= k ; i++) cout << '0';
        n-=k;
        int p = 1;
        while(m > n){
            cout << '1';
            m--;
            p = 0;
        }
        if(p){
            while(n--){
                cout << "10";
            }
        }else{
            while(n--){
                cout << "01";
            }
        }
    }
    cout << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
