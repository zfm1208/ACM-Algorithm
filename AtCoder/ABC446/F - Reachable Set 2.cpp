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
/*
    对于每个k，删除最少的顶点，使得从顶点1出发，能且仅能到达的顶点是{1,2,3...,k}
    <1>：内部联通:顶点1~k,必须能被顶点1走到, 且途中不能经过>k的点
    <2>: 外部隔离:绝对不能有任何一条路能从{1...k}走到>k的点

    
*/
void solve(){

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}