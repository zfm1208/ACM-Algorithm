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
struct node{
    int v,w;
};
void solve(){
    int n; cin >> n;
    vector<node> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i].v >> a[i].w;
    }
    auto check = [&] (int mid) -> bool {
        priority_queue<int> m,k;
        for(int i = 1;i <= n; i++){
            if(a[i].v >= mid){
                k.push(a[i].v + a[i].w);
            }else{
                m.push(a[i].w);
            }
        }
        while(!m.empty()){
            int top = m.top();
            if(k.empty()) return false;
            int kk = k.top();
            if(kk - top < mid) return false;
            k.pop();
            m.pop();
        }
        return true;
    };    
    int l = 1, r = 1e9;
    int ans = 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << ans << endl;
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