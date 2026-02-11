#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define dforn(i, n) for (int i = int(n)-1; i >= 0; i--)
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define dforsn(i, s, n) for (int i = int(n)-1; i >= int(s); i--)
#define all(x) x.begin(), x.end()
template <typename T>
int sz(const T &a) {
    return int(a.size());
}


struct Edge{
    int u;
    int v;
};

const int MAX = 1e5 + 5;
const int inf = 2e9;

vector<vector<int>> adj(MAX);
vector<int> low(MAX, inf);
vector<int> dis(MAX, -1);
vector<int> p(MAX, 0);
vector<Edge> res;

void dfs(int u) {
    for (auto v : adj[u]) {
        if (v == p[u]) continue; 
        if (dis[v] == -1) {
            dis[v] = dis[u] + 1;
            low[v] = min(low[v], dis[v]);
            p[v] = u;
            dfs(v);
        }
        low[u] = min(low[u], low[v]);
        if ( dis[v] > dis[u] && low[v] >= dis[v] ) {
            // cout << "u: " << u << " " << dis[u] << " " << low[u] << endl; 
            // cout << "v: " << v << " " << dis[v] << " " << low[v] << endl; 
            res.push_back({u, v});
        }
    }

}

void go() {

    int n, m;
    cin >> n >> m;
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dis[1] = 0;
    low[1] = 0;
    p[1] = 0;
    dfs(1);

    cout << sz(res) << endl;
    for (auto e : res) {
        cout << e.u << " " << e.v << endl;
    }

    // forn(i, n) {
    //     cout << "i : " << i + 1 << " " << dis[i + 1] << " " << low[i + 1] << endl;
    // }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    go();
    return 0;
}