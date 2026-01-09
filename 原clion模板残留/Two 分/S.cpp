//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define pi acos(-1.0)
#define se second
#define fi first
#define endl '\n'
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
bool check(){

}
void solve() {
    set<char> st;
    string s; cin >> s;
    int len = s.size();
    int n; cin >> n;
    rep(i,0,len-1) st.insert(s[i]);
    if(st.size() < n) cout << 0 << endl;
    else{
        int res = 0,cnt = 0;
        int cun[26] = {0};
        int l = 0, r = 0;
        while(r < len){
            if(cun[s[r] - 'a'] == 0)cnt++;
            cun[s[r] - 'a']++;
            r++;
            while(cnt >= n){
                res += len - r + 1;
                cun[s[l] - 'a']--;
                if(cun[s[l] - 'a'] == 0)cnt--;
                l++;
            }
        }
        cout << res << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
