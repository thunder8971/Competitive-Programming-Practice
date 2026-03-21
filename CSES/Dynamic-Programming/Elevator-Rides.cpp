#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define ln "\n"
template <typename T>
int sz(const T &x) {
    return int(x.size());
}
const int inf = 1e9;
void go() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    forn(i, n) {
        cin >> a[i];
    }
    vector<int> dp( 1 << n, inf);
    vector<int> w( 1 << n, 0);
    dp[0] = 1;
    forn (mask, 1 << n) {
        forn (i, n) {
            if (mask & (1 << i)) {
                continue;
            } else {
                int nx = mask | (1 << i);
                if (w[mask] + a[i] <= x) {
                    if (dp[mask] < dp[nx]) {
                        dp[nx] = dp[mask];
                        w[nx] = w[mask] + a[i];
                    } else if (dp[mask] == dp[nx]) {
                        w[nx] = min(w[nx], w[mask] + a[i]);
                    }
                } else {
                    if (dp[mask] + 1 < dp[nx]) {
                        dp[nx] = dp[mask] + 1;
                        w[nx] = a[i];
                    } else if (dp[mask] + 1 == dp[nx]) {
                        w[nx] = min(w[nx], a[i]);
                    }
                }
            }
        }
    }

    cout << dp[(1 << n) - 1] << ln;
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tt = 1;
    // cin >> tt;
    forn (tc, tt) {
        go();
    }
    return 0;
}