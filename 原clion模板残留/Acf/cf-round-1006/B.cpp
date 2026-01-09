//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if(n<3){
        cout << 0 << endl;
        return;
    }
    int s1 = 0, s2 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '_'){
            s1++;
        }else{
            s2++;
        }
    }
    int p1 = s2/2;
    int p2 = s2-p1;
    cout << p1*p2*s1 << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
