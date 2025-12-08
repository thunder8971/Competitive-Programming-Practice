#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define dforn(i, n) for (int i = int(n)-1; i >= 0; i--)
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define dforsn(i, s, n) for (int i = int(n)-1; i >= int(s); i--)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define endl '\n' 
const ll INF = 2e18;

void go() {
    int n;
    cin >> n;
    vector<ll> a(n),b(n);
    forn(i,n) {
        cin>>a[i]>>b[i];
    }
    auto bf = [&](ll x) -> ll {
        ll ret = x - 1 + n;
        ret %= n;
        return ret;
    };
    auto cst = [&](ll i) -> ll {
        return max(0ll, a[i] - b[bf(i)]);
    };
    ll s = 0;
    forn(i, n) {
        s += cst(i);
    }
    ll ans = INF;
    forn(i, n) {
        ll cur = s - cst(i) + a[i];
        ans = min(ans, cur);
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tt = 1;
    cin >> tt;
    forn (tc, tt) {
        go();
    }
}