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
const int MAX = 2e5 + 10;
int ds[MAX], wd[MAX], mn[MAX], A[MAX], B[MAX];

void build(int n) {
    forn(i, n + 1) {
        ds[i] = i;
        wd[i] = 1;
        mn[i] = A[i];
    }
}

int find(int x) {
    if (x == ds[x]) {
        return x;
    }
    return ds[x] = find(ds[x]);
}

void uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
        return;
    }
    if (wd[a] > wd[b]) {
        swap(a, b);
    }
    wd[b] += wd[a];
    ds[a] = b;
    mn[b] = min(mn[a], mn[b]);
}

struct Board{
    int h = 0;
    int id = 0;
    bool operator<(const Board &other) const {
        return h < other.h;
    }
};

void go() {
    int n;
    cin >> n;
    vector<Board> v;
    // Board cur;
    forn(i, n) {
        cin >> A[i + 1];
        // cur.h = A[i + 1];
        // cur.id = i + 1;
        v.push_back({A[i + 1], i + 1});
    }
    build(n);
    sort(all(v));
    ll ans = 0;
    dforn(i, n) {
        int id = v[i].id;
        if (id - 1 > 0 && B[id - 1]) {
            uni(id - 1, id);
        }
        if (id + 1 < n + 1 && B[id + 1]) {
            uni(id + 1, id);
        }
        int p = find(id);
        ll cur = (wd[p] * 1ll * mn[p]);
        ans = max(cur, ans);
        B[id] = 1;
    }
    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    go();
    return 0;
}