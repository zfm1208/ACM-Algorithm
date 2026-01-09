#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 10;
using namespace std;
void solve()
{
    int n;
    while(cin >> n and n){
        vector<int> a(n+10),l(n+10),r(n+10);
        for(int i = 1; i <= n; i++) cin >> a[i];
        stack<int> stk;
        //左边第一个比a[i] 小的位置
        for(int i = 1; i <= n; i++){
            while(!stk.empty() && a[stk.top()] >= a[i]) stk.pop();
            if(stk.empty()) l[i] = 0;
            else l[i] = stk.top();
            stk.push(i);
        }
        //清空栈
        while(!stk.empty()) stk.pop();
        //右边第一个比a[i] 小的位置
        for(int i = n; i >= 0; i--){
            while(!stk.empty() && a[stk.top()] >= a[i]) stk.pop();
            if(stk.empty()) r[i] = n+1;
            else r[i] = stk.top();
            stk.push(i);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans = max(ans, (r[i] - l[i] - 1) * a[i]);
        cout << ans << endl;
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

