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
    1011101
    1111111 - 7
    1010101 - 4

    100101101
    100111111 - 7
    100101011 - 5
*/
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int mx = 0,mn = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            if(i-1 >= 0 && i+1 < n && s[i-1] == '1' && s[i+1] == '1'){
                s[i] = '1';
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            mx++;
            cnt++;
        }else{
            if(cnt){
                mn += cnt/2 + 1;
                cnt = 0;                
            }
        }
    }
    if(cnt){
        mn += cnt/2 + 1;
    }
    cout << mn << " "<< mx << endl;
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