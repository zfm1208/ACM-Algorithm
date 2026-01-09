//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define int int
#define ull unsigned long long
#define pii pair<long long,long long>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
void solve() {
    int a,b;
    while(cin>>a>>b)
    {
        if(a>b){
            int t=a;a=b;b=t;
        }
        int k=b-a;
        double x=(sqrt(5)+1)/2;
        if(a==(int)(k*x))
            cout<<0<<endl;
        else
            cout<<1<<endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}
