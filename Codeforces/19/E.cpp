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

const int MAX = 1e4 + 5;
struct Edge{
    int u;
    int v;
    int ind;
};

vector<vector<Edge>> adj(MAX);
vector<Edge> edges;
vector<int> dis(MAX);
vector<int> col(MAX);
vector<int> pa(MAX);

vector<int> odd(MAX, 0);
vector<int> even(MAX, 0);

vector<int> even_cnt(MAX, 0);
vector<int> odd_cnt(MAX, 0);

vector<int> track;

vector<int> all_back;
set<int> back_odd;
set<int> tree;

void dfs(int u, int p) {
    track.push_back(u);
    for (auto edge : adj[u]) {
        int v = edge.v;
        int ind = edge.ind;
        if (v == p) continue;
        if (dis[v]) {
            if (dis[v] < dis[u]) {
                if (col[v] == col[u]) {
                    odd[u]++;
                    odd[v]--;
                    back_odd.insert(ind);
                    all_back.push_back(ind);
                } else {
                    even[u]++;
                    even[v]--;
                }
            }
        } else {
            dis[v] = dis[u] + 1;
            col[v] = dis[v] % 2;
            tree.insert(ind);
            pa[v] = ind;
            dfs(v, u);
        }
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
        edges.push_back({u, v, i});
    }

    int comp = 0;
    int total_back = 0;
    forsn(i, 1, n + 1) {
        if (dis[i]) continue;
        col[i] = dis[i] = 1;
        pa[i] = -1;
        back_odd.clear();
        dfs(i, 0);
        while (sz(track)) {
            int u = track.back();
            track.pop_back();
            if (pa[u] == -1) continue;
            int v = edges[pa[u]].u == u ? edges[pa[u]].v : edges[pa[u]].u;
            int ind = edges[pa[u]].ind;
            even_cnt[ind] += even[u];
            odd_cnt[ind] += odd[u];
            odd[v] += odd[u];
            even[v] += even[u];
        }
        if (sz(back_odd)) {
            comp++;
        }
        total_back += sz(back_odd);
    }

    vector<int> ans;

    if (comp == 0 ){
        forn(i, m) ans.push_back(i + 1);
    } else if (comp == 1) {
        if (total_back == 1) {
            ans.push_back(all_back[0] + 1);
        }
        forn(i, m) {
            if (odd_cnt[i] == total_back && even_cnt[i] == 0) {
                ans.push_back(i + 1);
            } 
        }
    }

    sort(all(ans));

    cout << sz(ans) << endl;
    for (auto e : ans) {
        cout << e << " ";
    }
    
    cout << endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    go();
    return 0;
}