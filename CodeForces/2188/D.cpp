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
int x,y;
const int pp[] = {0,0,1};
const int qq[] = {0,1,0};
int dp[32][3][3];
int vis[32][3][3];
int ch[32][3][3];
int dfs(int bit, int sp, int sq) {
    if(bit < 0) return 0;
    if(vis[bit][sp][sq]) return dp[bit][sp][sq];
    int ans = inf;
    int xx = (x >> bit) & 1;
    int yy = (y >> bit) & 1;
    for(int i = 0; i < 3; i++){
        int nsp = sp, nsq = sq;
        int p = pp[i];
        int q = qq[i];
        int cost = 0;
        if(sp == 0){
            if(p < xx){
                nsp = 1;
                cost += (1LL << bit);
            }else if(p > xx){
                nsp = 2;
                cost += (1LL << bit);
            }
        }else if(sp == 1){
            cost += ((xx - p) << bit);
        }else{
            cost += ((p - xx) << bit);
        }

        if(sq == 0){
            if(q < yy){
                nsq = 1;
                cost += (1LL << bit);
            }else if(q > yy){
                nsq = 2;
                cost += (1LL << bit);
            }
        }else if(sq == 1){
            cost += ((yy - q) << bit);
        }else{
            cost += ((q - yy) << bit);
        }
        int res = cost + dfs(bit-1, nsp, nsq);
        if(res < ans){
            ans = res;
            ch[bit][sp][sq] = i;
        }
    }
    vis[bit][sp][sq] = 1;
    return dp[bit][sp][sq] = ans;
}
void solve(){
    cin >> x >> y;
    memset(vis,0,sizeof(vis));
    dfs(30,0,0);
    int p = 0, q = 0;
    int sp = 0, sq = 0;
    for(int bit = 30; bit >= 0; bit--){
        int idx = ch[bit][sp][sq];
        int ip = pp[idx];
        int iq = qq[idx];
        int ix = (x >> bit) & 1LL;
        int iy = (y >> bit) & 1LL;
        if(ip) p |= (1LL << bit);
        if(iq) q |= (1LL << bit);
        if(sp == 0){
            if(ip < ix){
                sp = 1;
            }else if(ip > ix){
                sp = 2;
            }
        }

        if(sq == 0){
            if(iq < iy){
                sq = 1;
            }else if(iq > iy){
                sq = 2;
            }
        }
    }
    cout << p << " " << q << endl;
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