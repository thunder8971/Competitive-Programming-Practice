#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define dforn(i, n) for (int i = int(n)-1; i >= 0; i--)
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define dforsn(i, s, n) for (int i = int(n)-1; i >= int(s); i--)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define endl '\n' 
template <typename T>
int sz(T &a) {
    return int(a.size());
}

const int INF = 1e9;
const ll LLINF = 2e18;

void go() {
    int n, m;
    cin >> n >> m;
    int r, c;
    cin >> r >> c;
    r--, c--;
    int x, y;
    cin >> x >> y;
    vector<vector<char>> gr(n, vector<char>(m));
    forn (i, n) forn (j, m) cin >> gr[i][j];
    
    auto ok = [&](int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    };
    
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int cst[] = {0, 0, 0, 1};
    vector<vector<int>> dst(n, vector<int>(m, INF));
    deque<pii> dq;
    dq.push_back({r, c});
    dst[r][c] = 0;
    
    while (sz(dq)) {
        auto [i, j] = dq.front();
        dq.pop_front();
        int cstx = dst[i][j];
        
        forn(k, 4) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (!ok(ni, nj)) continue;
            if (gr[ni][nj] == '*') continue;
            int ncstx = cstx + cst[k];
            int ncsty = ncstx + nj - c;
            if (ncstx <= x && ncsty <= y && ncstx < dst[ni][nj]) {
                dst[ni][nj] = ncstx;
                if (cst[k] == 0) dq.push_front({ni, nj});
                else dq.push_back({ni, nj});
            }
        }
    }
    
    int ans = 0;
    forn(i, n) forn(j, m) if (dst[i][j] < INF) ans++;
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
}