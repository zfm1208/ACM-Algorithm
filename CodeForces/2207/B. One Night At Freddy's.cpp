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
/*
    m个玩偶,t秒,每秒有一个玩偶危险值+1
    n次照射,每次会让一个玩偶的危险值 = 0
    求最小x,使得玩偶的最大危险值永远不会超过x
*/
void solve(){
    int n, m, t; 
    cin >> n >> m >> t;
    vector<int> a(t + 1);
    rep(i, 1, n){
        int x; cin >> x;
        a[x] = 1;
    }
    vector<int> b(m+1);
    int rem = n; 
    for(int i = 1; i <= t; i++){
        sort(b.begin()+1, b.end(), greater<int>());        
        b[min(rem+1, m)]++; 
        if(a[i] == 0) continue;
        rem--; 
        int mx = -1,p = 1;
        for(int j = 1; j <= m; j++){
            if(b[j] > mx){
                mx = b[j];
                p = j;
            }
        }
        b[p] = 0;
    }  
    int ans = *max_element(b.begin()+1, b.end());
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

/*
    n-8 m-5 t-60
    3 17 20 28 36 44 45 50
    --19
*/