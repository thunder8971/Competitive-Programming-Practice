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
vector<vector<int>> adj;
int dfs(int u, vector<int> &d) {
    int ret = u;
    for (auto v : adj[u]) {
        if (d[v] == -1) {
            d[v] = d[u] + 1;
            int tmp = dfs(v, d);
            if (d[tmp] > d[ret]) {
                ret = tmp;
            }
        }
    }
    return ret;
}
void go() {
    int n;
    cin >> n;
    adj = vector<vector<int>>(n + 1);
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int p = 1, q = 1;
    vector<int> d(n + 1, -1);
    d[p] = 0;
    p = dfs(p, d);

    d = vector<int>(n + 1, -1);
    d[p] = 0;
    q = dfs(p, d);

    vector<int> pd(n + 1, -1), qd(n + 1, -1);
    pd[p] = 0;
    qd[q] = 0;
    deque<int> dq;
    dq.push_back(p);
    while (sz(dq)) {
        int u = dq.front();
        dq.pop_front();
        for (auto v :adj[u]) {
            if (pd[v] == -1) {
                pd[v] = pd[u] + 1;
                dq.push_back(v);
            }
        }
    }
    dq.push_back(q);
    while (sz(dq)) {
        int u = dq.front();
        dq.pop_front();
        for (auto v :adj[u]) {
            if (qd[v] == -1) {
                qd[v] = qd[u] + 1;
                dq.push_back(v);
            }
        }
    }

    forn(i, n) {
        cout << max(pd[i + 1], qd[i + 1]) << " ";
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
}