#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 1e5 + 5;
int a[N],b[N],cnt,ans1,ans2;
vector<int> c;
void solve2(){
    int x;
    while(cin >> x && x != EOF){
        bool s = 0;
        for(int i = 0; i < ans1; i++){
            if(a[i] < x){
                a[i] = x;
                s = 1;
                break;
            }
        }
        if(!s) a[ans1++] = x;
        s = 0;
        for(int i = 0; i < ans2; i++){
            if(b[i] >= x){
                b[i] = x;
                s = 1;
                break;
            }
        }
        if(!s) b[ans2++] = x;
    }
    cout << ans1 << endl << ans2 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) solve2();
    return 0;
}
