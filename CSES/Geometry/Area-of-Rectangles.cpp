#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define dforn(i, n) for (int i = int(n)-1; i >= 0; i--)
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define dforsn(i, s, n) for (int i = int(n)-1; i >= int(s); i--)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define ln '\n' 
template<typename T>
int sz(const T &a) {
    return int(a.size());
}


struct point {
    ll x, y;
};

struct event {
    point p, q;
    int t;

    bool operator<(const event &o) const {
        if (p.x == o.p.x) {
            return p.y < o.p.y;
        }
        return p.x < o.p.x;
    }

};

const ll MOD = 1e9 + 9;
const int MAX = 3e6 + 5;
const int off = 1e6 + 1;

struct node {
    ll cnt = 0;
    ll len = 0;
};

node st[4 * MAX];

ll query(int it, int l, int r, int a, int b) {
    if (r < a || l > b) {
        return 0;
    }
    if (a <= l && r <= b) {
        return st[it].len;
    }
    int m = (l + r) / 2;
    return query(2 * it, l, m, a, b) + query(2 * it + 1, m + 1, r, a, b);
}

void pull(int it, int l, int r) {
    if (st[it].cnt > 0) {
        st[it].len = r - l + 1;
    } else {
        if (l == r) {
            st[it].len = 0;
        } else {
            st[it].len = st[2 * it].len + st[2 * it + 1].len;
        }
    }
}

void update(int it, int l, int r, int a, int b, int v) {
    if (a > b) {
        return;
    }
    if (r < a || l > b) {
        return;
    }
    if (a <= l && r <= b) {
        st[it].cnt += v;
        pull(it, l, r);
        return;
    }
    int m = (l + r) / 2;
    update(2 * it, l, m, a, b, v);
    update(2 * it + 1, m + 1, r, a, b, v);
    pull(it, l, r);
}

void go() {
    
    int n;
    cin >> n;

    vector<event> v;
    forn (i, n) {
        point p, q;
        cin >> p.x >> p.y >> q.x >> q.y;
        p.x += off;
        p.y += off;
        q.x += off;
        q.y += off;
        event e1, e2;
        e1.p = p;
        e1.q = q;
        e1.t = 0;
        e2.p = q;
        e2.q = p;
        e2.t = 1;
        v.push_back(e1);
        v.push_back(e2);
    }

    sort(all(v));

    ll area = 0;
    ll lstx = v[0].p.x;

    update(1, 1, MAX, v[0].p.y, v[0].q.y - 1, 1);

    forsn(i, 1, sz(v)) {

        area += (v[i].p.x - lstx) *st[1].len;
        lstx = v[i].p.x;
        if (v[i].t == 0) {
            update(1, 1, MAX, v[i].p.y, v[i].q.y - 1, 1);
        } else {
            update(1, 1, MAX, v[i].q.y, v[i].p.y - 1, -1);
        }

    }

    cout << area << ln;
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tt = 1;
    // cin >> tt;
    forn (tc, tt) {
        go();
    }
    return 0;
}