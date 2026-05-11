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
int op;
void solve(){
    int n,m,k; cin >> m >> n >> k;
    vector<string> name(n, "");
    vector<int> dj(n, 0);
    set<int> st;
    for(int i = 0; i < n; i++) st.insert(i);
    map<string, vector<int>> pos1, pos2;
    set<string> h3;
    for(int i = 0; i < m; i++){
        string s; cin >> s;
        if(h3.count(s)) continue;
        int x = 1;
        if(pos1[s].size() == k-1){
            for(int id : pos1[s]){
                name[id] = "";
                dj[id] = 0;
                st.insert(id);
            }
            pos1[s].clear();
            x = 2;
            if(pos2[s].size() == k-1){
                for(int id : pos2[s]){
                    name[id] =  "";
                    dj[id] = 0;
                    st.insert(id);
                }
                pos2[s].clear();
                x = 3;
            }
        }
        if(!st.empty()){
            int id = *st.begin();
            st.erase(st.begin());
            name[id] = s;
            dj[id] = x;
            if(x == 1) pos1[s].push_back(id);
            else if(x == 2) pos2[s].push_back(id);
            else h3.insert(s);
        }
    }
    cout << "Case " << ++op << ":";
    for (int i = 0; i < n; i++) {
        cout << " ";
        if (dj[i] == 0) {
            cout << "-1";
        } else if (dj[i] == 1) {
            cout << name[i];
        } else if (dj[i] == 2) {
            cout << name[i] << "2";
        } else if (dj[i] == 3) {
            cout << name[i] << "3";
        }
    }
    cout << "\n";
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