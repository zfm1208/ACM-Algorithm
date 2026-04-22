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
// https://qoj.ac/contest/1834/problem/9703
/*
    思路: 遇到这种 “占比是否小于某个定值” 的问题，
    要联想到质数的密度是随着数字增大而不断递减的
    所以当[L,R] 的长度R-L+1不断增大时,区间质素/R-L+1的比值会越来越小, 当区间长度大于一定值时一定满足题意

    区间长度 1000 以内直接暴力
    1000以外直接YES
*/
bool check(int x){
    if(x == 1) return true; // 这一题1虽然不是素数但满足题意
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
void solve(){
    int l,r; cin >> l >> r;
    if(r - l + 1 >= 1000){
        cout << "Yes" << endl;
        return;
    }
    int cnt = 0;
    for(int i = l; i <= r; i++){
        if(check(i)) cnt++;
    }
    if(cnt * 3 < r-l+1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
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