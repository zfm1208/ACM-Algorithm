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
    string s; cin >> s;
    stack<char>st;
    for(int i = 0; i < n; i++){
        if(!st.empty() && st.top() == s[i]){
            st.pop();
        }else{
            st.push(s[i]);
        }
    }
    cout << (st.empty() ? "YES" : "NO") << endl;
}
void solve1(){
    int n; cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    bool op = 1;
    while(op&1){
        op = 0;
        int l = -1;
        for(int i = 1; i <= n; i++){
            if(s[i] != '*'){
                if(l != -1 && s[i] == s[l]){
                    s[i] = s[l] = '*';
                    op = 1;
                    l = -1;
                }else{
                    l = i;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(s[i] != '*'){
            cout << "NO" << endl;
            return;
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