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
/*
    如果右边的元素s[i]克制左边的元素s[i-1]，
    那么左边的元素在金字塔向上的传导中会被“截断”或“覆盖”。
    因此，我们可以维护一个单调栈。
    每当新进来的元素能打败栈顶元素时，说明栈顶元素无法“存活”到最后，将其弹出。
    最终栈底的元素，就是那个“从未被右边邻居打败”的最左侧强者，也就是金字塔顶端的赢家。
*/
void solve(){
    string s; cin >> s;
    int n = s.size();
    stack<char>st;
    st.push(s[0]);
    map<array<char,2>,int> mp;
    mp[{'P','R'}] = 1;
    mp[{'S','P'}] = 1;
    mp[{'R','S'}] = 1;
    for(int i = 1; i < n; i++){
        while(st.size() && mp[{s[i],st.top()}]){
            st.pop();
        }
        st.push(s[i]);
    }
    while(st.size() >= 2) st.pop();
    cout << st.top() << endl;
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