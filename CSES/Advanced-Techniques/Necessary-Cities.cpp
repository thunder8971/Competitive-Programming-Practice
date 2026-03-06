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

const int MAX = 1e5 + 5;
const int inf = 2e9;

vector<vector<int>> adj(MAX);
vector<int> low(MAX, inf);
vector<int> tin(MAX, 0);
vector<int> art(MAX, 0);
int timer;
vector<int> res;

void dfs(int u, int p) {
    tin[u] = low[u] = timer++;
    int children = 0;

    for (auto v : adj[u]) {
        if (v == p) continue;

        if (tin[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if (p != 0 && low[v] >= tin[u]) {
                art[u] = 1;
            }
            children++;
        }
    }

    if (p == 0 && children > 1) {
        art[u] = 1;
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
    
    timer = 1;

    forsn (i, 1, n + 1) {
        if (!tin[i]) {
            dfs(i, 0);
        }
    }

    forsn (i, 1, n + 1) {
        if (art[i]) {
            res.push_back(i);
        }
    }

    cout << sz(res) << "\n";
    forn(i, sz(res)) {
        cout << res[i]<< " \n"[i + 1 == sz(res)];
    }
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    go();
    return 0;
}