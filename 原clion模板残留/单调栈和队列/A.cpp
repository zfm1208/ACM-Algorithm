#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
const int N = 2e5 + 10;
using namespace std;
void solve()
{
    int n; cin >> n;
    vector<int> a(n+1),b(n+1);
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    stack<int> st;
    for(int i = n; i >= 1; i --){
        while(!st.empty() && a[st.top()] <= a[i])
            st.pop();
        if(!st.empty())
            b[i] = st.top();
        st.push(i);
    }
    for(int i = 1; i <= n; i ++){
        cout << b[i] << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1;
//    cin >> T;
    while(T--) solve();
    return 0;
}

