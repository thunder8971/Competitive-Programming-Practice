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

const int MAX = 2e5 + 5;
const int inf = 1e9;
const int ninf = -1e9;
const ll linf = 1e18;
const ll nlinf = -1e18;

int A[MAX];
struct node{
    ll sf = 0;
    ll sum = 0;
    node operator + (const node &o) const {
        node res;

        res.sum = sum + o.sum;
        res.sf = max(o.sf, o.sum + sf);

        return res;
    }
};

const node nul = node{nlinf, 0};

node st[4 * MAX];

void build(int it, int l, int r) {
    if (l == r) {
        st[it].sf = A[l];
        st[it].sum = A[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * it, l, m);
    build(2 * it + 1, m + 1, r);
    st[it] = st[2 * it] + st[2 * it + 1];
} 

node query(int it, int l, int r, int a, int b) {
    if (l > b || r < a) return nul;
    if (l >= a && r <= b) return st[it];
    int m = (l + r) / 2;
    return query(2 * it, l, m, a, b) + query(2 * it + 1, m + 1, r, a, b);
}

void go() {

    int n, a, b;
    cin >> n >> a >> b; 

    forn (i, n) {
        cin >> A[i + 1];
    }

    build(1, 1, n);

    ll ans = nlinf;

    forsn (i, a, n + 1) {
        node cur = query(1, 1, n, i - a + 1, i);
        node prev = b > a ? query(1, 1, n, max(1, i - b + 1), i - a) : nul;
        ans = max({ans, cur.sum, prev.sf + cur.sum});
    }

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
    return 0;
}