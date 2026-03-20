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

void solve(){
    vector<vector<int>> a(10,vector<int>(10));
    bool ok = true; 
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            cin >> a[i][j];
            if(a[i][j] < 1 || a[i][j] > 9){
                ok = false;
            }
        }
    }
    if(!ok){
        cout << 0 << endl;
        return;
    }
    for(int i = 1; i <= 9; i++){
        set<int> st;
        for(int j = 1; j <= 9; j++){
            st.insert(a[i][j]);
        }
        if(st.size() != 9){
            cout << 0 << endl;
            return;
        }
    }

    for(int j = 1; j <= 9; j++){
        set<int> st;
        for(int i = 1; i <= 9; i++){
            st.insert(a[i][j]);
        }
        if(st.size() != 9){
            cout << 0 << endl;
            return;
        }
    }
    auto check = [&](int x, int y) -> bool {
        set<int> st;
        for(int i = x; i < x+3; i++){
            for(int j = y; j < y+3; j++){
                st.insert(a[i][j]);
            }
        }
        return st.size() != 9;
    };
    if(check(1,1) || check(1,4) || check(1,7) ||
       check(4,1) || check(4,4) || check(4,7) ||
       check(7,1) || check(7,4) || check(7,7)){
        cout << 0 << endl;
        return;
    }
    cout << 1 << endl;
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