
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
const int N = 2e5 + 10;
using namespace std;
int pre[N];
int finds(int x) {
    if (pre[x] == x) return x;
    else return pre[x] = finds(pre[x]);
}
void unions(int x, int y) {
    int fax = finds(x);
    int fay = finds(y);
    if (fax!= fay) {
        pre[fax] = fay;
    }
}
void solve()
{
    int n,m,p,q; cin >> n >> m >> p >> q;
    for(int i = 1; i <= n + m; i ++) pre[i] = i;
    for(int i = 1; i <= p; i++){
        int x,y; cin >> x >> y;
        unions(x,y);
    }
    for(int i = 1; i <= q; i++){
        int x,y; cin >> x >> y;
        x*=-1;
        y*=-1;
        unions(x+n,y+n);
    }
    int max1=0,max2=0;
    for(int i = 1; i <= n; i ++){
        if(finds(i) == finds(1)) max1++;
    }
    for(int i = 1+n; i <= m+n; i ++){
        if(finds(i) == finds(1+n)) max2++;
    }
    cout << min(max1,max2);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1;
//    cin >> T;
    while(T--) solve();
    return 0;
}

