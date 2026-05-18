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

void solve() {
    string s; cin >> s;
    int hong = 0, hei = 0, bai = 0;
    int ans = 0;
    for(char c: s){
        if(c == 'W'){
            bai += hong + hei;
            hei = 0;
            hong = 0;
        }else if(c == 'R'){
            if(hei > 0){
                hei--;
                hong++;
            }else if(bai > 0){
                bai--;
                hong++;
            }else{
                ans++;
                hong++;
            }
        }else if(c == 'B'){
            if(hong){
                hong--;
                hei++;
            }else if(bai > 0){
                bai--;
                hei++;
            }else{
                ans++;
                hei++;
            }            
        }
    }
    cout << max(1LL, ans) << endl;
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