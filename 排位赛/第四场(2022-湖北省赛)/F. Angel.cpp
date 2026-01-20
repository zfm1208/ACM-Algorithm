#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N = 2e5+10,mod = 1e9+7;
#define rep(i,l,r) for(int i = l; i <= r; i++)
/*
    1 2 3 4 5
      x   p

*/
void solve(){
    int n; cin >> n;
    if(n == 1){
        cout << 1 << endl;
        cout << 1 << endl;
    }else if(n == 2){
        cout << 2 << endl;
        cout << 1 << " " << 1 << endl;
    }else if(n == 3){
        cout << 2 << endl;
        cout << 2 << " " << 2 << endl;
    }else {
        cout << 2*n-4 << endl;
        for(int i = 2; i < n; i++){
            cout << i << " ";
        }
        for(int i = n-1; i >= 2; i--){
            cout << i << " ";
        }
        cout << endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}