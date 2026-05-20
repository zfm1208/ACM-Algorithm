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
    int a,b,n,s;
    cin >> a >> b >> n >> s;
    int g = __gcd(a,b);
    if(s % g != 0){
        cout << "YES" << endl;
        rep(i,1,n) cout << a << " \n"[i == n];
        return;
    }
    a/=g;
    b/=g;
    s/=g;
    // gcd(a,b) == 1
    if(s % a != 0 || s > a * n){
        cout << "YES" << endl;
        rep(i,1,n) cout << a*g << " \n"[i == n];
        return; 
    }
    if(s % b != 0 || s > b * n){
        cout << "YES" << endl;
        rep(i,1,n) cout << b*g << " \n"[i == n];
        return;
    }

    // 此时s既是a的倍数，也是b的倍数
    // 并且 s <= n * a && s <= n * b
    if(s == a || s == b){
        cout << "NO" << endl;
        return;
    }
    if(a == 1) swap(a,b); 
    if(a == 2 && b == 1){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int k = s / a - 1;
    for(int i = 1; i <= n; i++){
        if(i % (k + 1) != 0){
            cout << a * g << " ";
        }else{
            cout << b * g << " ";
        }
    }
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