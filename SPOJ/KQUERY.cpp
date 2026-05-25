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

const int MAX = 3e4 + 5;
int n, q;
struct node{
    vector<int> v;
    node operator + (const node &o) const {
        node res;
        res.v.resize(sz(v) + sz(o.v));
        int i = 0, j = 0;
        while (i < sz(v) && j < sz(o.v)) {
            if (v[i] < o.v[j]) {
                res.v[i + j] = v[i];
                i++;
            } else {
                res.v[i + j] = o.v[j];
                j++;
            }
        }
        while (i < sz(v)) {
            res.v[i + j] = v[i];
            i++;
        }
        while (j < sz(o.v)) {
            res.v[i + j] = o.v[j];
            j++;
        }
        return res;
    }
};
int A[MAX];
vector<node> st(4 * MAX);
void build(int it, int l, int r) {
    if (l == r) {
        st[it].v.push_back(A[l]);
        return;
    }
    int m = (l + r) / 2;
    build(2 * it, l, m);
    build(2 * it + 1, m + 1, r);
    st[it] = st[2 * it] + st[2 * it + 1];
}

int query(int it, int l, int r, int a, int b, int k) {
    if (l > b || r < a) return 0;
    if (l >= a && r <= b) {
        return sz(st[it].v) - (upper_bound(all(st[it].v), k) - st[it].v.begin());
    }
    int m = (l + r) / 2;
    return query(2 * it, l, m, a, b, k) + query(2 * it + 1, m + 1, r, a, b, k);
}

void go() {

    cin >> n;
    forn (i, n) {
        cin >> A[i + 1];
    }
    build(1, 1, n);
    cin >> q;
    forn (i, q) {
        int l, r, k;
        cin >> l >> r >> k;
        int ans = query(1, 1, n, l, r, k);
        cout << ans << ln;
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