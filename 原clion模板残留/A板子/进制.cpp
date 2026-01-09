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
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
double pi = acos(-1);
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
void cs(){
    // 十进制数n 转换为11进制
    int n = 241575;
    stack<int> st;
    while(n){
        st.push(n%11);
        n/=11;
    }
    int ans = 0;
    while(!st.empty()){
        ans = ans * 10 + st.top();
        st.pop();
    }
    cout << ans<< endl;
    // 11进制数 ans 转换为十进制
    int s = 1;
    int res = 0;
    while(ans){
        res += (ans % 10) * s;
        s *= 11;
        ans /= 10;
    }
    cout << res << endl;
}
//十进制 dec
//十六进制：hex
//八进制：oct
void solve() {
    string s; cin >> s;
    int ja = -1;
    int jn = -1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '+'){
            ja = i;break;
        }
        if(s[i] == '-'){
            jn = i;break;
        }
    }
    int p = (ja == -1 ? jn : ja);
    string s1,s2;
    s1 = s.substr(0,p);
    s2 = s.substr(p + 1);
    if(s[p] == '+'){
        // 十六进制-> 十进制
        int x = stoll(s1,0,16);
        int y = stoll(s2,0,16);
        int sum = x + y;
        // 十进制-> 八进制
        cout << oct << sum << endl;
    }else{
        int x = stoll(s1,0,16);
        int y = stoll(s2,0,16);
        int sum = x - y;
        cout << oct << sum << endl;
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
