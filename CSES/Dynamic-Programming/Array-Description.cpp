#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define endl '\n'
template <typename T>
int sz(const T &x) {
    return int(x.size());
}
const int MOD = 1e9 + 7;
void go() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    forn(i, n) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    if (a[0] == 0) {
        forsn(j, 1, m + 1) {
            dp[0][j] = 1;
        }
    } else {
        dp[0][a[0]] = 1;
    }
    forsn(i, 1, n) {
        if (a[i] == 0) {
            forsn(j, 1, m + 1) {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
                if (j>= 2) {
                    dp[i][j] += dp[i - 1][j - 1];
                    dp[i][j] %= MOD;
                }
                if (j <= m - 1) {
                    dp[i][j] += dp[i - 1][j + 1];
                    dp[i][j] %= MOD;
                }
            }
        } else {
            dp[i][a[i]] += dp[i - 1][a[i]];
            dp[i][a[i]] %= MOD;
            if (a[i] >= 2) {
                dp[i][a[i]] += dp[i - 1][a[i] - 1];
                dp[i][a[i]] %= MOD;
            }
            if (a[i] <= m - 1) {
                dp[i][a[i]] += dp[i - 1][a[i] + 1];
                dp[i][a[i]] %= MOD;
            }
        }
    }
    ll ans = 0;
    forsn(j, 1, m + 1) {
        ans = (ans + dp[n - 1][j]) % MOD;
    }
    cout << ans << endl;
}   
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tt = 1;
    // cin >> tt;
    forn (tc, tt) {
        go();
    }
}