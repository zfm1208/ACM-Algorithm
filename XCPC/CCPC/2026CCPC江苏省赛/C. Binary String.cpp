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
    int n; cin >> n;
    string s; cin >> s;
    int cn=0;
    for(char c: s) if(c == '1') cn++;
    if(cn % 2 == 0){
        rep(i,1,n-1) cout << "^";
    }else{
        if(cn != 1){
            int ok = 1;
            for(int i = 0; i < n - 1; i++){
                if(s[i] == '1' && ok){
                    ok = 0;
                    cout << "&";
                }else{
                    cout << "^";
                }
            }            
        }else{
            if(s[n-1] == '1'){
                rep(i,1,n-2) cout << "^";
                cout << "&";
            }else{
                int ok = 1;
                for(int i = 0; i < n - 1; i++){
                    if(s[i] == '1' && ok){
                        ok = 0;
                        cout << "&";
                    }else{
                        cout << "^";
                    }
                }  
            }

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