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
/*
    5 
    xc 1 , 4 --- xj 1, 3 --- 1,2  or  2, 1 xj  0;    
*/
void solve(){
    int n;
    cin >> n;
    if(n <= 2){
        cout << "xiaocheng" << endl;
    }else{
        cout << "xiaoju" << endl;
    }
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