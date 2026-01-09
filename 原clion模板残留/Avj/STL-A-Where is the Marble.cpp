#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
const int N = 2e5 + 10;
using namespace std;
void solve()
{
    int n,q,pos = 0;
    while(cin >> n >> q && n && q)
    {
        cout << "CASE# " << ++pos << ":" <<endl;
        vector<int> a(n,0),b(n,0);
        for(auto & i : a){
            cin >> i;
        }
        sort(a.begin(),a.end());
        for(int i = 0;i < q;i++){
            cin >> b[i];
            auto it = find(a.begin(),a.end(),b[i]);
            if(it != a.end()){
                cout << b[i] << " found at " << it - a.begin() + 1 << endl;
            }
            else{
                cout << b[i] << " not found" << endl;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1;
//    cin >> T;
    while(T--) solve();
    return 0;
}

