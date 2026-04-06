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
// JAVA -- 高精度暴力代码
// import java.util.Scanner;
// import java.math.BigInteger;
// public class Main{
//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         BigInteger x = sc.nextBigInteger();
//         BigInteger ans = BigInteger.ONE;
//         BigInteger cnt = BigInteger.ONE;
//         while(!ans.remainder(x).equals(BigInteger.ZERO)){
//             cnt = cnt.add(BigInteger.ONE);
//             ans = ans.multiply(BigInteger.TEN).add(BigInteger.ONE);
//         }
//         System.out.println(ans.divide(x) + " " + cnt);
//     }
// }
void solve(){
    int x; cin >> x;
    int ans = 1;
    int n = 1;
    while(n < x){
        ans++;
        n = n * 10 + 1;
    }
    while(1){
        cout << n / x;
        if(n % x == 0){
            break;
        }
        n = n % x;
        n = n * 10 + 1;
        ans++;            
    }
    cout << " " << ans;
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