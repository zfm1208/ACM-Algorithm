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
    int l,r,u,d; 
    cin >> l >> r >> d >> u;
    int sum = 0;
    for(int i = l; i <= r; i++){
        if(i == 0){
            sum += (u - d + 1) / 2;
            if((u - d + 1) & 1){
                if(u % 2 == 0){
                    sum ++;
                }
            }
        }else{
            int lie = abs(i);
            if(lie % 2 == 0){
                if(d >= 0){
                    if(u <= lie){
                        sum += u - d + 1;
                    }else{
                        if (d <= lie) {
                            sum += lie - d + 1;
                            sum += u / 2 - lie / 2; 
                        } else {
                            sum += u / 2 - (d - 1) / 2; 
                        }
                    }
                }else{
                    if(u <= 0){
                        int fd = abs(u);
                        int fu = abs(d);
                        if(fu <= lie){
                            sum += fu - fd + 1;
                        }else{
                            if (fd <= lie) {
                                sum += lie - fd + 1;
                                sum += fu / 2 - lie / 2; 
                            } else {
                                sum += fu / 2 - (fd - 1) / 2;
                            }
                        }
                    }else{
                        int fd = 0;
                        int fu = u;
                        if(fu <= lie){
                            sum += fu - fd + 1;
                        }else{
                            sum += lie - fd + 1;
                            sum += fu / 2 - lie / 2;
                        }
                        fd = 0;
                        fu = abs(d);
                        if(fu <= lie){
                            sum += fu - fd + 1;
                        }else{
                            sum += lie - fd + 1;
                            sum += fu / 2 - lie / 2;
                        }
                        sum --;
                    }
                }
            }else{
                if(d >= 0){
                    if(u > lie){
                        if (d <= lie) {
                            sum += u / 2 - lie / 2;
                        } else {
                            sum += u / 2 - (d - 1) / 2;
                        }
                    }
                }else{
                    if(u <= 0){
                        int fd = abs(u);
                        int fu = abs(d);
                        if(fu > lie){
                            if (fd <= lie) {
                                sum += fu / 2 - lie / 2;
                            } else {
                                sum += fu / 2 - (fd - 1) / 2;
                            }
                        }
                    }else{
                        int fd = 0;
                        int fu = abs(d);
                        if(fu > lie){
                            sum += fu / 2 - lie / 2;
                        }
                        fd = 0;
                        fu = abs(u);
                        if(fu > lie){
                            sum += fu / 2 - lie / 2;
                        }
                    }
                }
            }
        }
    }
    cout << sum << endl;
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