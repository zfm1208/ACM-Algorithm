#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 10;
using namespace std;
stack<int> stk;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    int sum = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++){
        while(!stk.empty() && a[stk.top()] <= a[i]){
            stk.pop();
        }
        sum += stk.size();
        stk.push(i);
    }
    cout << sum << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1;
//    cin >> T;
    while(T--) solve();
    return 0;
}

