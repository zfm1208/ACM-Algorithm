#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4e5+10;
const int mod = 1e9+7;
void fff(){
    int  n;
    cin >> n;
    /*
        1*1 + 2*1 + 2*2 + 3*2 + 3*3 + 4*3 + 4*4 + 5*4 + 5*5 +

         .... + n*(n-1) + n*n
        1*1 + 2*2 + 3*3 + ... + n*n +
        1    5   14   30  55
        2*0 + 2*1 + 3*2 + ... + n*(n-1)
        0 + 2 + 6 + 12 + 20 + 30
        0   2   8   20   40   70

    */

    __uint128_t sum = 0;
    // for(int i = 1; i <= n; i++){
    //     sum += i*i;
    // }
    // cout << sum << " " << n*(2*n+1)*(n+1)/6 << endl;
    sum = n*(2*n+1) *(n+1)/ 6;
    // sum = 0;
    // for(int i = 1; i <= 10; i++){
    //     sum += i*(i-1);
    //     if(i!=1)
    //     // cout << sum << " " << i*(i-1) << " " << i << " " << sum / ((i-1)*i) << endl;
    // }
    // cout << sum << " " << endl;
    sum = n*(2*n+1) *(n+1) * 337 + n * (n-1) * (n+1) *  674;
    sum = sum % mod;
    cout << (int)sum << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T=1;
    cin >> T;
    while(T--){
        fff();
    }
    return 0;
}