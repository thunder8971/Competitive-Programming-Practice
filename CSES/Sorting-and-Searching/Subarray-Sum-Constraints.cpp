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

struct Edge {
    int v, w;
};
vector<vector<Edge>> adj;
vector<int> vis;
vector<ll> val;
bool impossible = false;
void dfs(int u) {
    vis[u] = 1;
    for (auto e : adj[u]) {
        int v = e.v, w = e.w;
        if (!vis[v]) {
            val[v] = val[u] + w;
            dfs(v);
        } else {
            if (val[v] != val[u] + w) {
                impossible = true;
                return;
            }
        }
    }
}

void go() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1, 0);
    val.resize(n + 1, 0);
    forn (i, m) {
        int l, r, s;
        cin >> l >> r >> s;
        adj[l - 1].push_back({r, s});
        adj[r].push_back({l - 1, -s});
    }
    forn (i, n) {
        if (!vis[i]) {
            val[i] = 0;
            dfs(i);
        }
    }
    if (impossible) {
        cout << "NO" << ln;
    } else {
        cout << "YES" << ln;
        forsn (i, 1, n + 1) {
            cout << val[i] - val[i - 1] << ' ';
        }
        cout << ln;
    }
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