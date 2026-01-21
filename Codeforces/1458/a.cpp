#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define endl '\n' 
void go() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);
    forn(i, n) {
        cin >> a[i];
    }
    forn(i, m) {
        cin >> b[i];
    }
    sort(all(a));
    ll g = 0;
    forsn(i, 1, n) {
        g = __gcd(g, a[i] - a[0]);
    }
    forn(i, m) {
        ll ans = __gcd(a[0] + b[i], g);
        cout << ans << " ";
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