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
void solve1(){
    int n,m; cin >> n >> m;    
    // has[x] = {}, 编号为x的大猴子被选择小猴子的编号集合
    vector<vector<int>> has(m+1);
    // v[i] = {a,b} : 第i只小猴子选择大猴子 a,b
    vector<array<int,2>> v(n+1);
    for(int i = 1; i <= n; i++){
        int a,b; cin >> a >> b;
        has[a].pb(i);
        has[b].pb(i);
        v[i] = {a,b};
    }
    
    // siz[i] : 第i只大猴子被小猴子选择的次数
    vector<int> siz(m+1);
    // mp[x] = {} 被选择x次的大猴子编号集合
    map<int,vector<int>> mp;
    int mx = 0;
    for(int i = 1; i <= m; i++){
        siz[i] = has[i].size();
        mx = max(mx, siz[i]);
        mp[siz[i]].pb(i);
    }
    
    // sh[x] 数组：用于记录“当前选定的大王”与“猴子x”有多少条共同的边
    vector<int> sh(m + 1, 0);

    if(mp[mx].size() == 1){
        int cmx = 0; 
        for(int i = mx-1; i >= 0; i--) {
            if(mp[i].size()){
                cmx = i;
                break;
            }
        }
        
        int u = mp[mx][0]; 
        for(int i : has[u]){
            auto [a, b] = v[i];
            int other = (a == u) ? b : a; 
            sh[other]++; 
        }
        
        int ans = 0;
        for(int i : mp[cmx]){
            ans = max(ans, mx + cmx - sh[i]);
        }
        cout << ans << endl;
        
    } else {
        int ans = 0;
        int sz = mp[mx].size();
        if(sz * (sz - 1) / 2 > n) {
            ans = mx * 2;
            cout << ans << endl;
            return;
        }
        for(int u : mp[mx]){
            for(int i : has[u]){
                auto [a, b] = v[i];
                int other = (a == u) ? b : a;
                sh[other]++;
            }
            for(int i : mp[mx]){
                if(u < i){ 
                    ans = max(ans, mx * 2 - sh[i]);
                }
            }
            
            for(int i : has[u]){
                auto [a, b] = v[i];
                int other = (a == u) ? b : a;
                sh[other]--;
            }
        }
        cout << ans << endl;
    }
}
void solve(){
    int n,m; cin >> n >> m;
    // has[x] = {}, 编号为x的大猴子被选择小猴子的编号集合
    vector<vector<int>> has(m+1);
    // v[i] = {a,b} : 第i只小猴子选择大猴子 a,b
    vector<array<int,2>> v(n+1);
    for(int i = 1; i <= n; i++){
        int a,b; cin >> a >> b;
        has[a].pb(i);
        has[b].pb(i);
        v[i] = {a,b};
    }
    // siz[i] : 第i只大猴子被小猴子选择的次数
    vector<int> siz(m+1);
    // mp[x] = {} 被选择x次的大猴子编号集合
    map<int,vector<int>> mp;
    int mx = 0;
    for(int i = 1; i <= m; i++){
        siz[i] = has[i].size();
        mx = max(mx, siz[i]);
        mp[siz[i]].pb(i);
    }
    // {x,id} : 当前猴子被选择的次数siz[x], 该猴子的编号
    set<array<int,2>> st;
    if(mp[mx].size() == 1){
        int cmx = 0;
        for(int i = mx-1; i >= 0; i--) if(mp[i].size()){
            cmx = i;
            break;
        }
        for(int x: mp[cmx]){
            st.insert({siz[x],x});
        }
        int mx_id = mp[mx].front();
        for(auto& i: has[mx_id]){
            auto [a,b]  = v[i];
            if(st.count({siz[a],a})){
                st.erase({siz[a],a});
                siz[a]--;
                st.insert({siz[a],a});
            }
            if(st.count({siz[b],b})){
                st.erase({siz[b],b});
                siz[b]--;
                st.insert({siz[b],b});
            }
        }
        cout << mx + (*st.rbegin())[0] << endl;
    }else{
        int ans = 0;
        for(int i : mp[mx]) st.insert({siz[i],i});
        for(auto id: mp[mx]){
            st.erase({siz[id],id});
            for(auto & i: has[id]){
                auto [a,b] = v[i];
                if(st.count({siz[a],a})){
                    st.erase({siz[a],a});
                    siz[a]--;
                    st.insert({siz[a],a});
                }
                if(st.count({siz[b],b})){
                    st.erase({siz[b],b});
                    siz[b]--;
                    st.insert({siz[b],b});
                }
            }
            ans = max(ans, mx + (*st.rbegin())[0]);
            for(auto & i: has[id]){
                auto [a,b] = v[i];
                if(st.count({siz[a],a})){
                    st.erase({siz[a],a});
                    siz[a]++;
                    st.insert({siz[a],a});
                }
                if(st.count({siz[b],b})){
                    st.erase({siz[b],b});
                    siz[b]++;
                    st.insert({siz[b],b});
                }
            }
            st.insert({siz[id], id});            
        }
        cout << ans << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve1();
    return 0;
}