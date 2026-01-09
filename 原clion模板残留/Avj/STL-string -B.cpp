#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
const int N = 2e5 + 10;
using namespace std;
string str;
string a;
bool check(char c){
    if(c >= 'a' && c <= 'z') return true;
    if(c >= 'A' && c <= 'Z') return true;
    return false;
}
void solve()
{
    set<string> s;
    while(getline(cin,str)){
        str += ' ';
        for(int i = 0;i < str.size();i++){
            if(check(str[i])){
                if(str[i] >= 'a' && str[i] <= 'z') a += str[i];
                else a += (str[i] - 'A' + 'a');
            }else{
                if(a.size()){
                    s.insert(a);
                    a.clear();
                }else{
                    // 空格,标点符号......
                }
            }
        }
    }
    for(auto i : s) cout << i << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1;
//    cin >> T;
    while(T--) solve();
    return 0;
}

