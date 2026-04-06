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
    string s;
    int x;
    int id;
};
void solve(){
    int n,g,k; cin >> n >> g >> k;
    map<int,int> mp;
    vector<node> a(n+1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        int x; cin >> x;
        if(x>=60 && x < g) ans += 20;
        else if(x >= g && x <= 100) ans += 50;
        mp[x]++;
        a[i] = {s,x,i};
    }
    sort(a.begin()+1,a.end(),[](auto aa, auto bb){
        if(aa.x == bb.x){
            return aa.s < bb.s;
        }
        return aa.x > bb.x;
    });
    cout << ans << endl;
    int lst = 1;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(i == 1){
            cout << 1 << " " << a[i].s << " " << a[i].x << endl;
            lst = 1;
            cnt++;
        }else{
            if(a[i].x == a[i-1].x){
                cout << lst << " " << a[i].s << " " << a[i].x << endl;
                cnt++;
                if(cnt >= k){
                    if(mp[a[i].x] != 1) continue;
                    else break;
                }
            }else{
                if(cnt >= k) break;
                cout << i << " " << a[i].s << " " << a[i].x << endl;
                lst = i;
                cnt++;
            }
        }
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