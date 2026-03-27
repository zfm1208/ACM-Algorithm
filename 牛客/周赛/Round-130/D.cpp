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
int ksm(int a,int b, int mod){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
// 除法的逻辑
// 不断取余数
// 第n位小数,就是第n-1位余数*10 / b
/*
    1/7 = 0.142857
    1> 1 * 10 % 7 = 1 余 3  1 * 10 % 7
    2> 3 * 10 % 7 = 4 余 2  1 * 10 * 10 % 7
    3> 2 * 10 % 7 = 2 余 6  1 * 10 * 10 * 10 % 7
    4> 6 * 10 % 7 = 8 余 4  1 * 10 * 10 * 10 * 10 % 7
*/
void solve(){
    int a,b; cin >> a >> b;
    for(int i = 2; i <= 1000; i++){
        for(int j = 1; j < i; j++){
            if(__gcd(i,j) == 1){
                if((j * ksm(10, a-1, i) % i) * 10 / i == b){
                    cout << j << " " << i << endl;
                    return;
                }    
            }
        }
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