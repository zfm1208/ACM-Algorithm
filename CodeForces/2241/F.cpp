#include<bits/stdc++.h>
using namespace std;
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
    int n; string s;
    cin >> n >> s;
    int l = -1, r = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            l = i;
            break;
        }
    }
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == '0'){
            r = i;
            break;
        }
    }
    if(l == -1 || r == -1 || l > r){
        cout << "Bob" << endl;
        return;
    }
    bool ok = false;
    for(int i = l; i <= r; ){
        int j = i;
        while(j <= r && s[j] == s[i]) j++;
        int len = j - i;
        if(len == 1){
            ok = true;
        }
        i = j;
    }
    if(ok) cout << "Alice" << endl;
    else cout << "Bob" << endl;
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