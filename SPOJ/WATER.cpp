#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define dforn(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
#define all(x) x.begin(), x.end()
#define mk make_pair
#define ff first
#define ss second
#define ln '\n'
template <typename T>
int sz(const T &x) {
    return int(x.size());
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct tower {
    int h, x, y;
    bool operator<(const tower& ot) const {
        return h < ot.h;
    }
};

void go() {

    int n, m;
    cin >> n >> m;
    int v[n][m];
    forn (i, n) {
        forn (j, m) {
            cin >> v[i][j];
        }
    }

    multiset<tower> s;
    int h[n][m];
    int vis[n][m];
    forn (i, n) {
        forn (j, m) {
            vis[i][j] = 0;
        }
    }

    forn (i, n) {
        for (auto j : {0, m - 1}) {
            vis[i][j] = 1;
            h[i][j] = v[i][j];
            tower aux;
            aux.h = h[i][j];
            aux.x = i;
            aux.y = j;
            s.insert(aux);
        }
    }

    forn (j, m) {
        for (auto i : {0, n - 1}) {
            vis[i][j] = 1;
            h[i][j] = v[i][j];
            tower aux;
            aux.h = h[i][j];
            aux.x = i;
            aux.y = j;
            s.insert(aux);
        }
    }

    while (sz(s)) {
        tower cur = *s.begin();
        s.erase(s.begin());
        forn (k, 4) {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            h[nx][ny] = max(cur.h, v[nx][ny]);
            tower aux;
            aux.h = h[nx][ny];
            aux.x = nx;
            aux.y = ny;
            s.insert(aux);
        }
    }

    ll ans = 0;
    forn (i, n) {
        forn (j, m) {
            ans += h[i][j] - v[i][j];
            // cout << h[i][j] << " \n"[j == m - 1]; 
        }

    }

    cout << ans << ln;  

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    cin >> tt;
    
    forn (tc, tt) {
        go();
    }

    return 0;
}