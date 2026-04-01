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
    int a,b,c;;
    auto get = [&](double x, double y) -> bool {
        return (((double) a*x*x + (double)b * x * y  + (double)c * y * y) < -1e-10);
    };    
    while(cin >> a >> b >> c){
        bool ok = 0;
        for(double x = -10; x<=10; x += 0.05){
            for(double y = -10; y<=10; y += 0.05){
                if(get(x,y)){
                    cout << "No" << endl;
                    ok = 1;
                    break;
                }
            }
            if(ok) break;
        }
        if(!ok)cout << "Yes" << endl;
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