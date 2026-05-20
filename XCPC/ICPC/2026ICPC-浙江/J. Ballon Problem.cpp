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
int lowbit(int x){ return x & (-x);}

struct node{
    int op,x,y;
};
struct BIT {
    int n;
    vector<int> tree;
    BIT (int _n):n(_n),tree(_n+1, 0) {}

    void add(int x, int val){
        for(int i = x; i <= n; i += lowbit(i)) {
            tree[i] += val;
        }
    }
    int query(int x){
        int res = 0;
        for(;x > 0; x -= lowbit(x)){
            res += tree[x];
        }
        return res;
    }
    int check(int k){
        int l = 1, r = n;
        int ans = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            if(query(mid) >= k){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};
void solve(){
    int q,c; cin >> q >> c;
    vector<node> hang, lie;
    vector<node> cz(q+1);
    for(int i = 1; i <= q; i++){
        cin >> cz[i].op >> cz[i].x >> cz[i].y;
        if(cz[i].op == 1){
            hang.push_back({i,cz[i].x, cz[i].y});
        }else if(cz[i].op == 2){
            lie.push_back({i, cz[i].x, cz[i].y});
        }
    }
    int n = hang.size() + 1;
    int m = lie.size() + 1;
    vector<pii> phang(n+1), plie(m+1);
    vector<int> ti_hang(q+1), ti_lie(q+1);
    BIT bit1(n);
    for(int i = 1; i <= n; i++){
        bit1.add(i,1);
    }
    for(int i = (int)hang.size() - 1; i >= 0; i--){
        auto [time, x, y] = hang[i];
        int pos = bit1.check(x+1);
        ti_hang[time] = pos;
        phang[pos] = {time, y};
        bit1.add(pos,-1);
    }
    int p1 = bit1.check(1);
    phang[p1] = {0, c};
    ti_hang[0] = p1;

    BIT bit2(m);
    for(int i = 1; i <= m; i++){
        bit2.add(i,1);
    }    
    for(int i = (int)(lie.size() - 1); i >= 0; i--){
        auto [time, x, y] = lie[i];
        int pos = bit2.check(x+1);
        ti_lie[time] = pos;
        plie[pos] = {time, y};
        bit2.add(pos, -1);
    }
    int p2 = bit2.check(1);
    plie[p2] = {0, c};
    ti_lie[0] = p2;

    bit1.tree.assign(n+1,0);
    bit2.tree.assign(m+1,0);

    bit1.add(ti_hang[0],1);
    bit2.add(ti_lie[0],1);
    for(int i = 1; i <= q; i++){
        auto[op, x, y] = cz[i];
        if(op == 1){
            bit1.add(ti_hang[i],1);
        }else if(op == 2){
            bit2.add(ti_lie[i],1);
        }else{
            int p1 = bit1.check(x);
            int p2 = bit2.check(y);            
            if(phang[p1].fi < plie[p2].fi){
                cout << plie[p2].second << endl;
            }else{
                cout << phang[p1].second << endl;
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