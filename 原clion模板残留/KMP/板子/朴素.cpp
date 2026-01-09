#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
//KMP（Knuth-Morris-Pratt）
//寻找字符串中子串的位置 --串的模式匹配
int find_sub_string (string s, string t){
    int i = 0,j = 0; //初始化两个指针
    while(i < s.size() && j < t.size()){
        if(s[i] == t[j]){ //如果两个指针指向的字符相等
            i++,j++; //则将两个指针向后移动
        }else{
            i = i - j + 1; //匹配失败，i退回到上次匹配首位的下一位
            j = 0;  //j退回到子串首位
        }
    }
    if(j >= t.size()) return i - j; //j走到子串末尾说明匹配成功
    else return -1;                 // 返回主串中子串出现的第一位
}
void solve() {
    string s,t; cin >> s >> t;
    cout << find_sub_string(s,t) << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}
