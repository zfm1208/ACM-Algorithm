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
    int n,k; cin >> n >> k;
    string s; cin >> s;
    s = " " + s;
    int ans = 0;
    int cnt = N;
    vector<int> v;
    for(int i = 1; i <= n; i++){
        if(s[i] == 'L') cnt++;
        else{
            if(cnt>0){
                v.push_back(cnt);
                ans++;
            }else{
                ans+=2;
            }
            cnt = 0;
        }
    }
    if(k == 0){
        cout << ans << endl;
        return;
    }
    if(cnt == n + N){
        cout << 2 * k -1 << endl;
        return;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        if(k >= v[i]){
            ans += 2 * v[i];
            ans++; // 对后面W 贡献1
            k -= v[i];
        }
    }
    ans += k * 2;
    ans = min(ans, 2 * n - 1);
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
