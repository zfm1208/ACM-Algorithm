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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
/*
    T:ababa
    T:abab

    不要顺着题目的操作去模拟，而是去对剩余长度的选择进行限制
    比如
    <1> 当剩余长度为奇数,那要么是ababa 要么是babab
    1. ababa
    我们此时能选的只能是a，没得选择
    2.babab
    我们此时能选的只能是b，没得选择

    <2> 当剩余长度为偶数,那要么是abab 要么是baba
    1. abab
    我们此时可以自由选择a / b
    假如选a,那下次只能选b;假如选b,那下次只能选a
    (b,a) (a,b)

    2. baba
    我们此时可以自由选择a / b
    假如选a,那下次只能选b;假如选b,那下次只能选a
    (b,a) (a,b)

    所以当长度为偶数时,我们连续的两次操作一定选的是(a,b) 或者(b,a)
    
    我们去像,假如一开始n是奇数,我们不难发现s[0] 一定是 'a' / '?' ，不可能是'b'
    这样剩下的就是偶数段了
    对于偶数段，我们2个2个去判断，(a,b)(b,a)(a,?)(b,?)(?,a)(?,b)(?,?)都是可行的
    不行的只有(a,a)(b,b) 我们直接暴力判断即可
*/
void solve(){
    int n;cin >> n;
    string s; cin >> s;
    if(n&1){
        if(s[0] == 'b'){
            cout << "NO" << endl;
            return;
        }
        for(int i = 1; i < n; i+=2){
            if(s[i] == s[i+1] && s[i] != '?'){
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
    }else{
        for(int i = 0; i < n; i+=2){
            if(s[i] == s[i+1] && s[i] != '?'){
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
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