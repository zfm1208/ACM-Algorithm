#include<bits/stdc++.h>
#define int long long
using namespace std;


void gty() {
    int n;
    cin >> n;
    int cnt = 0;
    while (n--) {
        string s;
        cin >> s;
        if (s.size() == 5 && s[0] != s[1] && s[0] != s[2] && s[1] != s[2] && s[0] != s[3] && s[1] != s[3] &&
            s[2] != s[3]) {
            if (s[2] == s[4]) cnt++;
        }
    }
    cout << cnt << endl;

}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
//    cin>>t;
    while(t--){
        gty();
    }
    return 0;
}