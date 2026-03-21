#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define dforn(i, n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i, s, n) for (int i = int(n)-1; i >= int(s); i--)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define endl '\n'
template <typename T>
int sz(const T &x) {
    return int(x.size());
}
const int inf = 1e9;
void go() {
    int n, x;
    cin >> n >> x;
    int a[n];
    forn(i, n) {
        cin >> a[i];
    }
    vector<int> dp(x + 1, inf);
    dp[0] = 0;
    forn (i, x + 1) {
        forn (j, n) {
            if (i >= a[j]) {
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
    }
    cout << (dp[x] == inf ? -1 : dp[x]) << endl;
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