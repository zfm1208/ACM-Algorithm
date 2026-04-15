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
    int n; cin >> n;
    vector<int> a(n+1),b(n+1);
    for(int i = 1;  i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    int ans = 0;
    sort(b.begin()+1,b.end());
    unordered_map<int,int> mp;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        mp[a[i]]++;
        if(mp[a[i]]==1) cnt++;
        mp[b[i]]--;
        if(mp[b[i]]==0) cnt--;
        if(cnt == 0) ans++;
    }
    cout << ans << endl;
}
/*
    要想在位置 i 和 i+1 之间合法地“切一刀”划分出一个新组，
    必须满足一个绝对条件：
    左边这部分元素的最大值，必须小于等于右边剩余所有元素的最小值。
*/
void solve1(){
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    vector<int> mn(n+1);
    mn[n] = a[n];
    for(int i = n - 1; i >= 1; i--) {
        mn[i] = min(mn[i + 1], a[i]);
    }
    int ans = 1; 
    int mx = 0; 
    for(int i = 1; i < n; i++){
        mx = max(mx, a[i]);
        if(mx <= mn[i + 1]) ans++;
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve1();
    return 0;
}