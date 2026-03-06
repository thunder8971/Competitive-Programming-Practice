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
    int ind;
};

const int MAX = 1e4 + 5;
vector<vector<Edge>> adj(MAX);
vector<Edge> Edges;
set<int> bads;
vector<int> col(MAX, 0);

void dfs(int u,int p) {
    for (auto cur : adj[u]) {
        int v = cur.v;
        int ind = cur.ind;
        if (v == p) {
            continue;
        }
        if (col[v] != 0) {
            if ( col[u] == col[v] ) {
                bads.insert(ind);
            }
            continue;
        }
        col[v] = 3 - col[u];
        dfs(v, u);
    }
}

void go() {

    int n, m;
    cin >> n >> m;

    forn (i, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({u, v, i});
        adj[v].push_back({v, u, i});
        Edges.push_back({u, v, i});
    }

    col[1] = 1;
    dfs(1, 0);

    // cout << " ------ " << "\n";
    // for (auto e : bads) {
    //     cout << e << "\n";
    // }
    // cout << " ------ " << "\n";

    if (sz(bads) > 1) {
        cout << 0 << "\n";
        return;
    }

    if (sz(bads) == 1) {
        cout << 1 << "\n";
        cout << (*bads.begin()) + 1 << "\n";
        return;
    }

    cout << m << "\n";
    forn (i, m) {
        cout << i + 1 << " ";
    }
    cout << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    go();
    return 0;
}