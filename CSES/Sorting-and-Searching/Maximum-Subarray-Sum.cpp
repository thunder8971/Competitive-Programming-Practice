#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define ln '\n'
template <typename T>
int sz(const T &x) {
    return int(x.size());
}

void go() {
    int n;
    cin >> n;
    vector<int> v(n);
    forn(i, n) {
        cin >> v[i];
    }
    vector<ll> p(n + 1, 0);
    forn(i, n) {
        p[i + 1] = p[i] + v[i];
    }
    ll mn = 0, ans = -1e18;
    forsn(i, 1, n + 1) {
        ans = max(ans, p[i] - mn);
        mn = min(mn, p[i]);
    }
    cout << ans << ln;
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