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
const int N = 1e3+6, mod = 1e9+7, inf = 1e18 + 5;

void solve(){
    int n,m; cin >> n >> m;
    map<int,int> pos;
    vector<int> h(N);
    int sz = 0;
    auto up = [&] (int u) -> void {
        while(u / 2 >= 1 && h[u/2] > h[u]){
            swap(h[u/2], h[u]);
            pos[h[u/2]] = u/2;
            pos[h[u]] = u;
            u /= 2;
        }
    };
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        h[++sz] = x;
        pos[x] = sz;
        up(sz);
    } 
    while(m--){
        int x,y; 
        string s1,s2,s3,s4;
        cin >> x >> s1;
        if(s1 == "and"){
            cin >> y >> s2 >> s3;
            if(pos[x] / 2 == pos[y] / 2) cout << "T" << endl;
            else cout << "F" << endl;
        }else if(s1 == "is") {
            cin >> s2;
            if (s2 == "the") {
                cin >> s3;
                if (s3 == "root") {
                    if(pos[x] == 1) cout << "T" << endl;
                    else cout << "F" << endl;
                } else if (s3 == "parent") {
                    cin >> s4 >> y; 
                    if (pos[x] == pos[y] / 2) cout << "T" << endl;
                    else cout << "F" << endl;
                }
            } else if (s2 == "a") {
                cin >> s3 >> s4 >> y; 
                if (pos[x] / 2 == pos[y]) cout << "T" << endl;
                else cout << "F" << endl;
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