//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define eb emplace_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
double pi = acos(-1);
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
void solve() {
    int n; cin >> n;
//    vector<int> a;
//    map<int,int> mp;
//    for(int i = 1; i <= 5; i++){
//        for(int j = 1; j <= 5; j++){
//            mp[i+j]++;
//            cout << i+j << " ";
//        }
//        cout << endl;
//    }
//    cout << mp.size() << endl;
    if(n==1){
        cout << 1 << endl << 1 << endl;
        return;
    }
    if(n == 2 || n == 4) {
        cout << "-1" << endl;
        return;
    }
    if(n & 1){
        int x = (n + 1)/2;
        cout << x << endl;
        for(int i = 1; i <= x; i ++)
            cout << i << " \n"[i == x];
    }
    else{
        int x = n / 2;
        cout << x << endl;
        for(int i = 1; i < x; i ++) cout << i << " ";
        cout << x + 1 << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
//    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}