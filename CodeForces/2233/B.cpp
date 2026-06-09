#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for(int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
int a2[] = {1,2,1,1,2,2,1,2};// 15
int a3[] = {1,1,2,1,2,3,1,3,2,2,3,3};
int a0[] = {1,4,3,4,4,3,3,1,2,1,2,3,4,2,2,1};
int a1[] = {5,3,2,4,1,2,2,4,4,5,3,5,2,1,3,1,5,4,1,3};
void solve(){
    int n; cin >> n;
    vii ans;
    if(n % 4 == 0){
        int op = 0;
        while(op < n){
            rep(i, 0, 15) ans.pb(a0[i] + op);
            op += 4;
        }

    } else if(n % 4 == 1){
        int op = 0;
        rep(i, 0, 19) ans.pb(a1[i] + op);
        op += 5;
        while(op < n){
            rep(i, 0, 15) ans.pb(a0[i] + op);
            op += 4;
        }
    } else if(n % 4 == 2){
        int op = 0;
        rep(i, 0, 7) ans.pb(a2[i] + op);
        op += 2;
        while(op < n){
            rep(i, 0, 15) ans.pb(a0[i] + op);
            op += 4;
        }
    } else if(n % 4 == 3){
        int op = 0;
        rep(i, 0, 11) ans.pb(a3[i] + op);
        op += 3;
        while(op < n){
            rep(i, 0, 15) ans.pb(a0[i] + op);
            op += 4;
        }
    }
    for(int x: ans) cout << x << " ";
    cout << endl;
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