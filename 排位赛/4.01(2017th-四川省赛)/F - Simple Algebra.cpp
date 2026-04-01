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
// f(x,y) = a * x * x + b * x * y + c * y * y
// f(x,y) = y^2 (a * (x/y) ^ 2 + b(x/y) + c)
// f(x,y) >= 0
// 令t = x/y
// g(t) = a* t^2 + b* t + c >= 0
// b^2 - 4ac <= 0
void solve(){
    int a,b,c;;
    while(cin >> a >> b >> c){
        if(a >= 0 && c >= 0 && (b*b-4*a*c <= 0)){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
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