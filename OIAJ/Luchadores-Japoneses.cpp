#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define dforn(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define ln '\n'
template <typename T>
int sz(const T &x) {
    return int(x.size());
}

const ll inf = 1e18;
const int MAX = 1e5 + 10;

struct Point {
    int x, y;
    int it;
    bool operator<(Point o) const {
        if (x == o.x) {
            return y < o.y;
        }
        return x < o.x;
    }
};

struct node {
    int sum;   
    node operator+(node ot) {
        return {sum + ot.sum};
    } 
};

vector<node> st(4*MAX);

node query(int it, int l, int r, int a, int b) {
    if (r < a || l > b) {
        return {0};
    }
    if (a <= l && r <= b) {
        return st[it];
    }
    int mid = (l + r) / 2;
    node lf = query(2 * it, l, mid, a, b);
    node rg = query(1 + 2 * it,mid + 1, r, a, b);
    return lf + rg;
}

void update(int it, int l, int r, int x, node val) {
    if (r < x || l > x) {
        return;
    }
    if (l == r) {
        st[it] = st[it] + val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * it, l, mid, x, val);
    update(1 + 2 * it, mid + 1, r, x, val);
    st[it] = st[2 * it] + st[1 + 2 * it];
}

vector<Point> flaty(vector<Point> &v) {
    vector<Point> ret;
    vector<int> ys;
    map<int, int> mp;
    for (auto it:v) {
        ys.push_back(it.y);
    }
    sort(all(ys));
    forn(i, sz(ys)) {
        mp[ys[i]] = i;
    }

    forn(i, sz(v)) {
        ret.push_back({v[i].x, mp[v[i].y], v[i].it});
    }

    return ret;

}

void go() {

    int n;
    cin >> n;
    vector<Point> v;
    forn(i, n) {
        int x, y, it;
        cin >> x >> y;
        it = i;
        v.push_back({x, y, it});
    }
    vector<int> ans(n);
    v = flaty(v);
    sort(all(v));
    map<Point, int> mp;
    forn(i, n) {
        mp[{v[i].x,v[i].y, 0}]++;
        update(1, 0, n, v[i].y, {1});
        ans[v[i].it] = query(1, 0, n, 0, v[i].y).sum - mp[{v[i].x, v[i].y, 0}]; 
    }

    for(auto e:ans) {
        cout << e << ln;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    forn (tc, tt) {
        go();
    }
    return 0;
}