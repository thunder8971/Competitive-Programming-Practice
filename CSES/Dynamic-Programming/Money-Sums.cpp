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
void go() {
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n) {
        cin >> a[i];
    }
    sort(all(a));
    vector<int> dp(100*1005, 0);
    dp[0] = 1;
    forn(i, n) {
        for(int j = 100*1005 - a[i] - 1; j >= 0; j--) {
            if (dp[j]) {
                dp[j + a[i]] = 1;
            }
        }
    }
    int cnt = 0;
    forsn(i, 1, 100*1005) {
        cnt += dp[i];
    }
    cout << cnt << endl;
    forsn(i, 1, 100*1005) {
        if (dp[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
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