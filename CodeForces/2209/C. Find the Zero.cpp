#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
// #define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
int ask(int i, int j){
    cout << "? " << i << " " << j << endl;
    int op; cin >> op;
    if(op == -1) exit(0);
    return op;
}
int ans(int k){
    cout << "! " << k << endl;
    return 0; 
}
void solve(){
    int n; cin >> n;
    int res = 1;
    for(int i = 1; i <= 2*(n-1); i+=2){
        int op = ask(i,i+1);
        if(op == 1){
            ans(i);
        }
    } 
    if(ask(2*n-1,1) == 1){
        ans(2*n-1);
    }else if(ask(2*n-1,2) == 1){
        ans(2*n-1);
    }else{
        ans(2*n);
    }
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