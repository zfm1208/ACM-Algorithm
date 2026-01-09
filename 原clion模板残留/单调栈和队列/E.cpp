#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 10;
using namespace std;

void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int> a(n+1),ans(n+1);
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    int h = 1, t = 0;
    for(int i = 1;i <= n;i++){
        while(t>=h && a[i] <= a[ans[t]]) t--;
        ans[++t] = i;
        if(ans[h] <= i-k) h++;
        if(i >= k) cout << a[ans[h]] << " ";
    }
    cout << endl;
    h = 1, t = 0;
    for(int i = 1;i <= n;i++){
        while(t>=h && a[i] >= a[ans[t]]) t--;
        ans[++t] = i;
        if(ans[h] <= i-k) h++;
        if(i >= k) cout << a[ans[h]] << " ";
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

