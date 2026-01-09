#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;

//void solve() {
//    int n;string s;
//    cin >> n >> s;
//    int cnt = 0;
//    for(int i = 0; i < n-8 ; i++)
//    {
//        if(s[i] == 'u')
//        {
//            for(int j = i + 2; j < n-7; j++){
//                if(s[j] == 'u' && s[j + 1] =='w'
//                   && s[j + 2] == 'a'&& s[j + 3] == 'w'
//                   && s[j + 4] == 'a' && s[j + 5] == 'u'
//                   && s[j + 6] == 'w' && s[j + 7] == 'a'){
//                    cnt ++;
//                }
//            }
//        }
//    }
//    cout << cnt << endl;
//}
void solve(){
    int n; string s;
    cin >> n >> s;
    int cnt = 0;
    vector<int> v;
    for(int i = 0; i <= n; ++i){
        if(i + 7 >= n) break;
        if (s[i] == 'u' && s[i+1] == 'w' && s[i+2] == 'a' &&
            s[i+3] == 'w' && s[i+4] == 'a' && s[i+5] == 'u' &&
            s[i+6] == 'w' && s[i+7] == 'a') {
            v.push_back(i);
        }
    }
    for(int i = 0; i < n; ++i){
        if(s[i] == 'u'){
            auto p = lower_bound(v.begin(), v.end(), i + 2);
            if(p != v.end()){
                cnt += v.end()-p;
            }
        }
    }
    cout << cnt << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}