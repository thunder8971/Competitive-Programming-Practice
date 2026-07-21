#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define dforn(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
#define all(x) x.begin(), x.end()
#define mk make_pair
#define ff first
#define ss second
#define ln '\n'
template <typename T>
int sz(const T &x) {
    return int(x.size());
}

ll mulmod(ll a, ll b, ll m) {
    return (a % m * b % m) % m;
}

ll binpowmod(ll a, ll b, ll m) {
    if (b == 0) return 1;
    if (b % 2) {
        return mulmod(a, binpowmod(a, b - 1, m), m);
    }
    return mulmod(binpowmod(a, b / 2, m), binpowmod(a, b / 2, m), m);
}

void go() {

    ll a, b, c;
    cin >> a >> b >> c;

    if (b == 0ll) {
        cout << 1 << ln;
        return;
    }

    map<ll, ll> mp;
    
    ll k = 0;
    ll cur = 1;
    ll i = 0;

    while (1) {
        if (mp.count(cur)) {
            k = i - mp[cur];
            break;
        }
        mp[cur] = i;
        i++;
        cur *= a;
        cur %= 10;
    }

    ll ex = (binpowmod(b, c, k) - 1) % k;

    ex += 2 * k;
    ex %= k;
    ex++;

    ll ans = binpowmod(a, ex, 10);

    cout << ans << ln;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    // cin >> tt;
    
    forn (tc, tt) {
        go();
    }

    return 0;
}