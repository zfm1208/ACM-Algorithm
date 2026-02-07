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

void solve(){
    vector<string> s(4);
    for(int i = 0; i < 3; i++){
        cin >> s[i];
    }
    auto check = [&] (char c) -> bool {
        bool ok = 0;
        for(int i = 0; i < 3; i++){
            int cnt = 0;
            for(int j = 0; j < 3; j++){
                if(s[i][j] == c){
                    cnt++;
                }
            }
            if(cnt == 3) return true;
        }
        for(int i = 0; i < 3; i++){
            int cnt = 0;
            for(int j = 0; j < 3; j++){
                if(s[j][i] == c){
                    cnt++;
                }
            }
            if(cnt == 3) return true;
        }
        if(s[0][0] == c && s[1][1] == c && s[2][2] == c){
            return true;
        }
        if(s[0][2] == c && s[1][1] == c && s[2][0] == c){
            return true;
        }
        return false;
    };
    if(check('+')){
        cout << '+' << endl;
    }
    else if(check('X')){
        cout << "X" << endl;
    }
    else if(check('O')){
        cout << "O" << endl;
    }
    else cout << "DRAW" << endl;
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