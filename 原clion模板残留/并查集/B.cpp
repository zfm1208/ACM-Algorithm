#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
const int N = 1e6 + 10;
using namespace std;
int n,m,q,x,y;
int pre[N];
int finds(int x){
    if(pre[x] == x) return x;
    else return pre[x] = finds(pre[x]);
}
bool vis[N];
void unides(int x,int y){
    int fax = finds(x);
    int fay = finds(y);
    if(fax != fay){
        pre[fax] = fay;
    }
}
void solve()
{
    cin >> n >> m >> q;
    for(int i = 1; i <= n*m; i++)
        pre[i] = i;
    while(q--){
        cin >> x >> y;
        unides(x,y);
    }
    int ans = 0;
    for(int i = 1; i <= n*m; i++){
        if(!vis[finds(i)]){
            ans++;
            vis[finds(i)] = 1;
        }
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1;
//    cin >> T;
    while(T--) solve();
    return 0;
}

