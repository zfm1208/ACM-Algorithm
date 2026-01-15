#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define fi first
#define se second
#define pii pair<int,int>
#define sort(a) sort(a.begin()+1,a.end())
#define endl '\n'
const int N = 1e6+5;

void fff(){
    int k; cin >> k;
    string s; cin >> s;
    int n,m; cin >> n >> m;
    rep(i,1,m) {
        int u,v; cin >> u >> v;
    }
    int op = m-n+1;
    op++;
    op %= k;
    if(op % k == 0) op = k;
    // cout << "op : "<< op << endl;
    op--;
    if(s[op] == '1') cout << 2 << endl;
    else cout << 1 << endl;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        fff();
    }
    return 0;
}