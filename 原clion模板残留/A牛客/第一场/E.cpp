#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
void solve() {
    int n;cin >> n;
    vector<int> arr(n+1);
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    sort(arr.begin()+1,arr.end());
    int t = n >> 1;
    int x = 0, y = 0;
    if(t & 1){
        x = t + 1 >> 1;
        y = t + x;
    }
    else{
        x = t >> 1;
        y = t + x + 1;
    }
    int mid1 = arr[x],mid2 = arr[y];
    int ans = 0;
    for(int i = 1;i <= n/2;i++){
        ans += abs(arr[i] - mid1);
        arr[i] -= mid1;
    }
    for(int i = n/2+1;i <= n;i++){
        ans += abs(arr[i] - mid2);
        arr[i] -= mid2;
    }
    if(mid1 == mid2){
        int ans1 = ans,ans2 = ans;
        for(int i = 1;i <= n/2;i++){
            if(arr[i] < 0) ans1--;
            else ans1++;
        }
        for(int i = n/2+1;i <= n;i++){
            if(arr[i] > 0) ans2--;
            else ans2++ ;
        }
        ans = min(ans1,ans2);
    }
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
