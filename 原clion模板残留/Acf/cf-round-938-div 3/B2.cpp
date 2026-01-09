#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 300005;
int b[N], e[N];
int a[505][505];
int main() {
    int _;
    scanf("%d", &_);
    while (_--) {
        int n, c, d;
        scanf("%d%d%d", &n, &c, &d);
        for (int i = 1; i <= n * n; i++) scanf("%d", &b[i]);
        sort(b + 1, b + n * n + 1);
        int tot = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) {
                    a[i][j] = b[1];
                } else if (j == 1) {
                    a[i][j] = a[i - 1][j] + c;
                } else {
                    a[i][j] = a[i][j - 1] + d;
                }
                e[++tot] = a[i][j];
            }
        }
        sort(e + 1, e + tot + 1);
        int ok = 1;
        for (int i = 1; i <= tot; i++) {
            if (b[i] != e[i]) {
                ok = 0;
                break;
            }
        }
        puts(ok ? "YES" : "NO");
    }
    return 0;
}