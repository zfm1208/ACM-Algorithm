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
    int x,y,cnt;
};
void solve(){
    int n,m; cin >> n >> m;
    vector<node> a(n+1);
    set<pii> st;
    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y;
        a[i].cnt = 0;
        st.insert({a[i].x, i});
    }
    for(int i = 1; i <= m; i++){
        int l,r,u,v;
        cin >> l >> r >> u >> v;
        auto it = st.lower_bound({l,0});
        vector<pii> shan,cun;
        for(; it != st.end() && (*it).first <= r;){
            int pos = (*it).second;
            shan.pb(*it);
            a[pos].x += u;
            a[pos].y += v;
            a[pos].cnt++;
            if(a[pos].cnt < 6){
                cun.pb({a[pos].x, pos});
            }
            it++;
        }
        for(auto &it1: shan){
            st.erase(it1);
        }
        for(auto &it1: cun){
            st.insert(it1);
        }
    }
    for(int i = 1; i <= n; i++){
        // cout << a[i].cnt << endl;
        if(a[i].cnt >= 6){
            cout << "Disappeared" << endl;
        }else{
            if(a[i].cnt == 0){
                cout << "Cumulus " << a[i].x << " " << a[i].y << endl;
            }else{
                cout << "Cirrus "<< a[i].x << " " << a[i].y << endl;
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