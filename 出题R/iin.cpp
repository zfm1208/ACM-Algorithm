#include <bits/stdc++.h>
#define int long long
using namespace std;

int random(int l, int r)
{
    return rand() % (r - l + 1) + l;
}

string get_filename()
{
    int idx = 1;
    while (true)
    {
        stringstream ss;
        ss << "test";
        if (idx < 10)
            ss << "0";
        ss << idx << ".in";
        ifstream fin(ss.str());
        if (!fin.good())
            return ss.str();
        idx++;
    }
}
// 生成长度1-5的随机小写字符串
string randomString() {
    const string chars = "abcdefghijklmnopqrstuvwxyz";
    // 随机生成长度（1-5）
    int len = random(1, 1);
    string res;
    // 循环生成每个字符
    for (int i = 0; i < len; ++i) {
        int idx = random(0, static_cast<int>(chars.size()) - 1);
        res += chars[idx];
    }
    return res;
}
signed main()
{
    srand(unsigned(time(0)));
    string filename = get_filename();
    freopen(filename.c_str(), "w", stdout);

    // 代码区: 
    int t = 1;
    // t = random(1,100);
    // cout << t << '\n';
    while (t--)
    {
        int n = random(1000, 2000);
        cout << n << endl;
        for(int i = 1; i <= n; i++){
           int x =  random(1,1e9);
           cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}