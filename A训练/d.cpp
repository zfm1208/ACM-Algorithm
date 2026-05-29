#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve(){
    int n; cin >> n;
    vector<int> h(n+1);
    rep(i,1,n) cin >> h[i];
    vii ans(n+1);
    h[0] = inf; 
    ans[0] = 1;
    stack<int> st;
    st.push(0);   
    for(int i = 1; i <= n; i++){
        while(st.size() > 1 && h[st.top()] <= h[i]){
            st.pop();
        }
        int j = st.top();
        ans[i] = ans[j] + (i - j) * h[i];
        st.push(i);
        cout << ans[i] << " ";
    }
    cout << endl;
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