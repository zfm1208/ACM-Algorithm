#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve(){
    int a,b; cin >> a >> b;
    int sum = a + b * 2;
    if(sum & 1){
        cout << "NO" << endl;
    }else{
        int ban = sum / 2;
        if(a == 0){
            if(ban  & 1){
                cout << "NO" << endl;
            }else{
                cout << "YES" << endl;
            }
        }else{
            cout << "YES" << endl;
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