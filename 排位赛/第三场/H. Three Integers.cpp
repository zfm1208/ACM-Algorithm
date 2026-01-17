#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N = 1e5+6,mod = 998244353;
#define rep(i,l,r) for(int i = l; i <= r; i++)
/*
    (1)x = k1 * y + a  (a < y)
    (2)y = k2 * z + b  (b < z)
    (3)z = k3 * x + c  (c < x)
    合并(1)(2)
    x = k1 * (k2 * z + b) + a

    x = k1 * k2 * z + k1 * b + a
    z = k3 * x + c
    或者这样看
    a = x - k1 * y >= 0
    b = y - k2 * z >= 0
    c = z - k3 * x >= 0
    (k1,k2,k3为非负整数)
    x >= k1 * y
    y >= k2 * z
    z >= k3 * x 

    x >= k1 * y >= k1 * k2 * z >= k1 * k2 * k3 * x
    得 k1*k2*k3 <= 1
    <1>若 k1*k2*k3 = 1  则 k1 = k2 = k3 = 1
        ==> 
        x = y+a;
        y = z+b;
        z = x+c;

        = > x = z+a+b
            z = x+c
        (得 a = b = c = 0)
    <2>若 k1*k2*k3 = 0 则 至少有一个为0
    
*/
void zfm(){
    int a,b,c; cin >> a >> b >> c;
    int x,y,z;
    // 注意到a,b,c的范围最大1e9,而所求答案x,y,z最大为1e18
    // for(int i = c+1; i <= c+100; i++){
    //     x = i;
    //     for(int j = a+1; j <= a+100; j++){
    //         y = j;
    //         if(x % y == a){
    //             for(int k = b+1; k <= b+100; k++){
    //                 z = k;
    //                 if(y%z== b && z % x == c){
    //                     cout << "YES" << endl;
    //                     cout << x << " " << y << " " << z << endl;
    // int k1 = (x-a)/y;
    // int k2 = (y-b)/z;
    // int k3 = (z-c)/x;
    // cout << k1 << " " << k2 << " " << k3 << endl;
    //                     return;
    //                 }
    //             }
    //         }
    //     }
    // }
    // cout << "NO" << endl;
    if(a == b && a == c){
        if(a != 0){cout << "NO" << endl; return;}
        cout << "YES" << endl;
        cout << 1 << " " << 1 << " " << 1 << endl;
        return;
    }
    cout << "YES" << endl;
    if(a > c){
        x = a;
        // z = k3 * a + c > b
        // y = k2*z > a
        int k = b/x + 10;
        z = k*x+c;
        y = z+b;
    }else if(b > a){
        y = b;
        int k = c/y + 10;
        x = k*y + a;
        z = x+c;
    }else if(c>b){
        z = c;
        int k = a/z + 10;
        y = k*z+b;
        x = y+a;
    }
    cout << x << " " << y << " " << z << endl;
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