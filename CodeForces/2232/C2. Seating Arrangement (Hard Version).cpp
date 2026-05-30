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
// I 空
// E 有人
// A 任意
void solve(){
    int n,x,s; cin >> n >> x >> s;
    string S; cin >> S; S = " " + S; 
    int ans = 0;
    int cntzz = 0 ;
    int cntzw = 0;
    int cnta  = 0;
    for(int i = 1; i <= n; i++){
        if(S[i] == 'I'){
            cntzz++;
            if(cntzz <= x){
                ans++;
                cntzw++;
            }else{
                cntzz--;
            }
        }else if(S[i] == 'A'){
            if(cntzw < cntzz * s){
                cntzw++;
                ans++;
                cnta++;
            }else{
                cntzz++;
                if(cntzz <= x){
                    ans++;
                    cntzw++;
                }else{
                    cntzz--;
                }
            }
        }else{
            if(cntzw < cntzz * s){
                cntzw++;
                ans++;
            }else{
                if(cnta > 0 && cntzz < x){
                    cnta--;
                    cntzz++;
                    cntzw++;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
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