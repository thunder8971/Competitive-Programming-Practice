#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, n) for (ll i = 0; i < ll(n); i++)
#define forsn(i, s, n) for (ll i = ll(s); i < ll(n); i++)
#define ff first
#define ss second
#define endl '\n' 
ll n, m;
vector<vector<ll>> adj;
vector<ll> DP;
vector<ll> DP2;
ll dp(ll u) {
    if (DP[u] != -1) return DP[u];
    ll res = 0;
    for (auto v : adj[u]) {
        if (v < u) {
            continue;
        }
        res += dp(v);
    }
    DP[u] = res;
    return res;
}
ll dp2(ll u) {
    if (DP2[u] != -1) return DP2[u];
    ll res = 0;
    for (auto v : adj[u]) {
        if (v < u) {
            continue;
        }
        if ((dp2(v) + dp(u)) > res) {
            res = dp2(v) + dp(u);
        }
    }
    DP2[u] = res;
    return res;
}
void go() {
    cin >> n >> m;
    adj = vector<vector<ll>> (n + 1);
    DP = vector<ll> (n + 1, -1);
    DP[n] = 1;
    DP2 = vector<ll> (n + 1, -1);
    DP2[n] = 1;
    forn (i, m) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans = dp2(1);
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
    return 0;
}