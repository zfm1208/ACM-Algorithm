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

void solve(){
    int n, m, k; 
    cin >> n >> m >> k;
    vector<int> a(m);
    rep(i, 0, m-1) cin >> a[i];
    sort(a.rbegin(), a.rend()); 
    vector<pii> fr(n);
    int sum = 0;
    rep(i, 0, n-1){
        int x, y, z; 
        cin >> x >> y >> z;
        sum += y;
        fr[i] = {x, z - y};
    }
    int rem = k - sum;
    sort(fr.begin(), fr.end(), [](pii x, pii y){
        return x.fi > y.fi;
    });
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> b; 
    int ih = 0;
    for(auto p : fr){
        auto [bt,x] = p;
        if(ih < m && a[ih] >= bt){
            pq.push(x);
            ih++;
        } 
        else {
            if(!pq.empty() && pq.top() < x){
                b.pb(pq.top()); 
                pq.pop();
                pq.push(x);
            }else{
                b.pb(x);
            }
        }
    }
    int ans = pq.size();
    sort(b.begin(), b.end());
    for(int x : b){
        if(rem >= x){
            rem -= x;
            ans++;
        }else{
            break;
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