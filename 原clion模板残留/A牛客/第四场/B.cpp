#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
int n;
bool check(string& s){
    int s01 = 0, s10 = 0;
    for(auto i = 0; i < n - 1; i++){
        if(s[i] == '0' && s[i + 1] == '1') s01++;
        if(s[i] == '1' && s[i + 1] == '0') s10++;
    }
    return (s01 == s10);
}
int get(string& s){
    int res = 0;
    for(int i = 0; i < n; i++){
        string s1 = s;
        if(s1[i] == '0') s1[i] = '1';
        else s1[i] = '0';
        if (check(s1)) res++;
    }
    return res;
}
int f1(string& s, int i, int cnt){
    if(i == n) return get(s);
    if(s[i] == '?'){
        cnt--;
        string s0,s1;
        s0 = s1 = s;
        s0[i] = '0',s1[i] = '1';
        return (f1(s0, i + 1, cnt) + f1(s1, i + 1, cnt)) % mod;
    }else{
        return f1(s, i + 1, cnt);
    }
}
void solve() {
    string s;
    cin >> n >> s;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '?') cnt++;
    }
    int ans = f1(s, 0, cnt);
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
