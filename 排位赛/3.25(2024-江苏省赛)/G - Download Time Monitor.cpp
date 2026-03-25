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

void solve(){
    int b,t1,a1,t2,a2;
    cin >> b >> t1 >> a1 >> t2 >> a2 ;
    if(t1 < t2){
        double na = a1 * 1.0 / b;
        if(t1 + na <= t2){
            double nb = a2*1.0 / b;
            cout << fixed << setprecision(9) << na << ' ';
            cout << fixed << setprecision(9) << nb << endl;
        }else{
            double ans1,ans2;
            ans1 += t2-t1;
            int a11 = a1 - ans1 * b;
            double gong = min(a11, a2) * 2.0 / b;
            ans1 += gong;
            ans2 += gong;
            int mn = min(a11, a2);
            a11 -= mn;
            a2 -= mn;
            if(a11 > 0){
                ans1 += (double)(a11 * 1.0 / b);
            }
            if(a2 > 0){
                ans2 += (double)(a2 * 1.0 / b);
            }
            cout << fixed << setprecision(9) << ans1 << ' ';
            cout << fixed << setprecision(9) << ans2 << endl;
        }
    }else if(t1 == t2){
            double ans1,ans2;
            ans1 += t2-t1;
            int a11 = a1 - ans1 * b;
            double gong = min(a11, a2) * 2.0 / b;
            ans1 += gong;
            ans2 += gong;
            int mn = min(a11, a2);
            a11 -= mn;
            a2 -= mn;
            if(a11 > 0){
                ans1 += (double)(a11 * 1.0 / b);
            }
            if(a2 > 0){
                ans2 += (double)(a2 * 1.0 / b);
            }
            cout << fixed << setprecision(9) << ans1 << ' ';
            cout << fixed << setprecision(9) << ans2 << endl;
    }else if(t1 > t2){
        double na = a2 * 1.0 / b;
        if(t2 + na <= t1){
            double nb = a1*1.0 / b;
            cout << fixed << setprecision(9) << na << ' ';
            cout << fixed << setprecision(9) << nb << endl;
        }else{
            double ans1,ans2;
            ans1 += t1-t2;
            int a22 = a2 - ans1 * b;
            double gong = min(a22, a1) * 2.0 / b;
            ans1 += gong;
            ans2 += gong;
            int mn = min(a22, a1);
            a22 -= mn;
            a1 -= mn;
            if(a22 > 0){
                ans1 += (double)(a22 * 1.0 / b);
            }
            if(a1 > 0){
                ans2 += (double)(a1 * 1.0 / b);
            }
            cout << fixed << setprecision(9) << ans1 << ' ';
            cout << fixed << setprecision(9) << ans2 << endl;
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