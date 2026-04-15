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
// https://qoj.ac/problem/6443

/*
    1 -3 2 -4
    ans = 1 - (-3 - (2 - (-4))) = 10
*/

/*
    a b c d
    <1>: a - b - c - d

    <2>: a - (b - c) - d
    a - b + c - d

    <3>: a - (b - c - d)
    a - b + c + d

    我们手玩样例不难发现 如果 数组里面 有正有负， ans = sum of abs(a[i])
    但如果全负或全正，ans = sum of abs(a[i])  -  2 * min(a[i])
*/
void solve(){
    int n; cin >> n;
    if(n == 1){
        int x; cin >> x;
        cout << x << endl;
        return;
    }    
    int sum = 0;
    int mn = inf;
    bool z = false,f = false;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(x>0) z = true;
        if(x<0) f = true;
        sum += abs(x);
        mn = min(mn, abs(x));
    }
    if(z && f){
        cout << sum << endl;
    }else{
        cout << sum - 2*mn << endl;
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