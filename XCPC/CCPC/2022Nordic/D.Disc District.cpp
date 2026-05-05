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
    int r; cin >> r;
    cout << r << " " << 1 << endl;
}
void solve1(){
    int r; cin >> r;
    int mn = -1;
    int ansx = -1, ansy = -1;
    for (int y = 0; y <= r; ++y) {
        int x = sqrt(r * r - y * y);
        while(x * x + y * y <= r * r){
            x++;
        }
        if(mn == -1 || x * x + y * y < mn) {
            mn = x * x + y * y;
            ansx = x;
            ansy = y;
        }
    }
    cout << ansx << " " << ansy << "\n";
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