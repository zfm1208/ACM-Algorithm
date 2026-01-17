#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N = 1e5+6,mod = 998244353;
#define rep(i,l,r) for(int i = l; i <= r; i++)
/*
    n = 2
    [1,2] 
    [2,1]
    
    n = 3
    [1,2,3]
    [1,3,2]
    [2,1,3]
    [2,3,1]
    [3,1,2]
    [3,2,1]

    n = 4
    [2,3,4,1]
    [2,4,3,1]
    [3,2,4,1]
    [3,4,2,1]
    [4,2,3,1]
    [4,3,2,1]
    [1,2,3] + [4]
    [1,3,2] + [4]
    [2,1,3] + [4]
    [2,3,1] + [4]
    [3,1,2] + [4]
    [3,2,1] + [4]

*/
int ksm(int a, int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b = b / 2;
    }
    return res;
}
void zfm(){
    int n; cin >> n;
    if(n == 1){
        cout << 1 << endl;
    }else if(n == 2){
        cout << 2 << endl;
    }else if(n == 3){
        cout << 6 << endl;
    }else{
        cout << ksm(2,n-2) % mod * 3 % mod << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        zfm();
    }
    return 0;
}