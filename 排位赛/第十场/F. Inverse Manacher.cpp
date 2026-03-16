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
/*
               p   p   p   p    
         1 2 3 4 5 6 7 8 9 10'11'12
    s =      a   b   a   a   a 
    T =  & | a | b | a | a | a |
    a[]: 1 1 2 1 4 1 2 3 4 3 2 1
             2   4   2   4   2
             1   2   1   2   1
             a   b   a   a   a
*/
void solve(){
    int n; cin >> n;
    vector<int> a(2*n+3);
    string ans = "a";
    for(int i = 1; i <= 2*n + 2; i++){
        cin >> a[i];
        if(i >= 4 && i % 2 == 0 && ans.size() < n){
            if(a[i] == 1){
                if(ans.back() == 'a'){
                    ans += 'b';
                }else{
                    ans += 'a';
                }
            }else{
                if(ans.back() == 'a'){
                    ans += 'a';
                }else{
                    ans += 'b';
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
    // cin >> T;
    while(T--)
        solve();
    return 0;
}