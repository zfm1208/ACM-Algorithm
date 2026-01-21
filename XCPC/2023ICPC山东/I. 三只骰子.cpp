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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

vector<int> red = {1, 4};
vector<int> black = {2, 3, 5, 6};
bool check(int pos, int cnt, vector<int>& ab) {
    if(cnt == 0) return pos == 0;    
    for(int p : ab){
        if(pos >= p){
            if(check(pos - p, cnt - 1, ab)) 
                return true;
        }
    }
    return false;
}

void solve(){
    int a, b; cin >> a >> b;
    for(int i = 0; i <= 3; i++){
        if(check(a, i, red) && check(b, 3 - i, black)){
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}