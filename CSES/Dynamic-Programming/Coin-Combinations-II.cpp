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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    forn(i, n) {
        cin >> a[i];
    }
    sort(all(a));
    vector<vector<int>> dp(n + 1, vector<int> (x + 1, 0));
    dp[0][0] = 1;
    forn(i, n) {
        forn (j, x + 1) {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= MOD;
            if (j + a[i] <= x) {
                dp[i + 1][j + a[i]] += dp[i + 1][j];
                dp[i + 1][j + a[i]] %= MOD;
            }
        }
    }
    cout << dp[n][x] << endl;
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