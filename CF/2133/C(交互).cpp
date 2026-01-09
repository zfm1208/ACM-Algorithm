#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
// #define endl '\n'
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
    我们要知道最多查询2*n次有什么隐讳含义
    可以分成n+n或者n + logn 
    然后我们读题可以知道，你要查询最长路径的长度应该要n次查询，
    好，那还剩下n次查询机会，你现在还要找路径里面的都是什么？ 
    我们可以想想就发现，正解应该是再次遍历，n次查询得到答案，
    那我们就想怎样n次查询可以得到路径上点呢?
    因为它是DAG，单向无环图，路径一定u -> v ,
    就是说从st -> ed路径上点每次查询时，得到的答案是递减的
    也就是和题目中的查询结果一样，可以进行判断

    还有一个要注意的点是，相同的路径长度可能有多个起始点，所以我们要开数组去存哪些点的最长长度是多少
    
    首先我们一定知道DAG 中最长路径的起点，这可以通过n次询问找到，
    我们再找最长路的时候用数组记录长度为len的点有哪些
    我们知道了最长路径长度mx，起点u，我们现在从最长路径mx-1的点开始查询一直到最长路径长度为1
    在查询时维护一个点集S表示最长路径的点，然后每次查询时把点集的点和即将要查询的点v进行输出查询，
    若返回的结果比集合里元素还长的话，说明该元素在最长路径上面，就可以将v加入点集S.
    在部分查询时，我们每次只会遍历S的元素一次，总共就是n次查询，满足题意

*/
void solve(){
    int n; cin >> n;
    int mx = 0;
    vector<vector<int>> pos(n+1);
    int sp;
    for(int i = 1; i <= n; i++){
        cout << "? " << i << " " << n << " ";
        rep(j,1,n) cout << j << " ";
        cout << endl;
        int len; cin >> len;
        if(len > mx){
            mx = len;
            sp = i;
        }
        pos[len].pb(i);
    }
    if(mx == 1){
        cout << "! 1 1" << endl;
        return;
    } 
    vector<int> path(mx);
    int ls = 1;
    for(int i = mx-1; i >= 1; i--,ls++){
        for(int j : pos[i]){
            cout << "? " << sp << " " << mx-i+1 << " " << sp << " ";
            for(int k = mx-1; k > i; k--) cout << path[k] << " ";
            cout << j << endl;
            int len; cin >> len;
            if(len > ls) path[i] = j;
        }
    }
    cout << "! " << mx << " " << sp << " ";
    for(int i = mx-1; i >= 1; i--) cout << path[i] << " ";
    cout << endl;
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