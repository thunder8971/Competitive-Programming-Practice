#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define ln '\n'
template <typename T>
int sz(const T &x) {
    return int(x.size());
}

const int MAX = 5e4 + 5;
const int inf = 1e9;
const int ninf = -1e9;
int n, q;
struct node{
    int lf = ninf;
    int sf = ninf;
    int tot = 0;
    int bst = ninf;
    node operator + (const node &o) const {
        node res;

        res.lf = max(lf, tot + o.lf);
        res.sf = max(o.sf, o.tot + sf);
        res.tot = tot + o.tot;
        res.bst = max({bst, o.bst, sf + o.lf});

        return res;
    }
};
node nul = node{ninf, ninf, 0, ninf};
int A[MAX];
vector<node> st(4 * MAX);
void build(int it, int l, int r) {
    if (l == r) {
        st[it].lf = A[l];
        st[it].sf = A[l];
        st[it].tot = A[l];
        st[it].bst = A[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * it, l, m);
    build(2 * it + 1, m + 1, r);
    st[it] = st[2 * it] + st[2 * it + 1];
}

node query(int it, int l, int r, int a, int b) {
    if (l > b || r < a) return nul;
    if (l >= a && r <= b) {
        return st[it];
    }
    int m = (l + r) / 2;
    return query(2 * it, l, m, a, b) + query(2 * it + 1, m + 1, r, a, b);
}

void update(int it, int l, int r, int pos, int v) {
    if (r < pos || l > pos) return;
    if (l == r) {
        st[it].lf = v;
        st[it].sf = v;
        st[it].tot = v;
        st[it].bst = v;
        return;
    }
    int m = (l + r) / 2;
    update(2 * it, l, m, pos, v);
    update(2 * it + 1, m + 1, r, pos, v);
    st[it] = st[2 * it] + st[2 * it + 1];
}

void go() {

    cin >> n;
    forn (i, n) {
        cin >> A[i + 1];
    }

    build(1, 1, n);

    cin >> q;
    forn (i, q) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 0) {
            update(1, 1, n, x, y);
        } else {
            cout << query(1, 1, n, x, y).bst << ln;
        }
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
    return 0;
}