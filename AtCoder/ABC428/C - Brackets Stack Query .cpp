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
    int q; cin >> q;
    int cnt = 0;
    int res = 0;// 垃圾时间计数器
    stack<char> st;// 合法状态栈
    while(q--){
        int op; cin >> op;
        if(op == 1){
            char c; cin >> c;
            // 如果还没跌破 0，正常入栈；否则进入垃圾时间，记录垃圾数量
            if(cnt >= 0) st.push(c);
            else res++;
            // 只有在非垃圾时间（!res）才更新 cnt
            // 一旦 cnt 变成负数，下次就不会再更新了，彻底锁死！
            if(c == '(' && !res) cnt++;
            if(c == ')' && !res) cnt--;
        }else{
            // 优先清空垃圾时间里乱加的字符
            if(res) res--;
            else{
                if(st.top() == '(') cnt--;
                else cnt++;
                st.pop();
            }
        }
        if(cnt != 0) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
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