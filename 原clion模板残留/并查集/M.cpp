#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
const int N = 2e5 + 10;
using namespace std;
int pre[N];
int val[N];
int finds(int x) {
    if (pre[x] == x) return x;
    else return pre[x] = finds(pre[x]);
}
void unions(int x, int y) {
    int fax = finds(x);
    int fay = finds(y);
    if (fax!= fay) {
        pre[fax] = fay;
        val[fay] += val[fax];
    }
}
void solve()
{
    int n,m; cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        cin >> val[i];
    for(int i = 1; i <= n; i ++)
        pre[i] = i;
    for(int i = 1; i <= m; i ++){
        int op; cin >> op;
        if(op == 1){
            int l,r; cin >> l >> r;
            for(int j = l; j < r; j ++){
                unions(j,j + 1);
            }
        }else{
            int x; cin >> x;
            int cnt = 0;
            for(int j = 1; j <= n; j ++){
                if(finds(j) == finds(x)) cnt ++;
            }
            double ans = (double)val[finds(x)] / cnt;
            printf("%.10lf\n",ans);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
//    cin >> T;
    while(T--) solve();
    return 0;
}

