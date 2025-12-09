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
const int MOD = 1e9 + 7;
void go() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>());
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> team(n + 1, -1);
    forsn(i, 1, n + 1) {
        if (team[i] != -1) continue;
        deque<int> dq;
        dq.push_back(i);
        team[i] = 0;
        while (sz(dq)) {
            int u = dq.front();
            dq.pop_front();
            for (auto v : adj[u]) {
                if (team[v] == -1) {
                    team[v] = 1 - team[u];
                    dq.push_back(v);
                } else if (team[v] == team[u]) {
                    cout << "IMPOSSIBLE" << endl;
                    return;
                }
            }
        }
    }
    forn(i, n) {
        cout << team[i + 1] + 1 << " ";
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
}