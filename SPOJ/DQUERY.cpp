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

const int MAX = 1e6 + 5;
int n,m;
int A[MAX], B[MAX], C[MAX];

struct dquery{
    int l, r, i;
    bool operator < (const dquery &o) const {
        return r == o.r ? l < o.l : r < o.r;
    }
};


struct node{
    int sum = 0;
};

vector<node> st(4 * MAX, node{0});

node merge(node a, node b) {
    return node{a.sum + b.sum};
}

node query(int in, int i, int j, int l, int r) {
    if (i > r || j < l) return node{0};
    if (i >= l && j <= r) return st[in];
    int m = (i + j) / 2;
    return merge(query(2 * in, i, m, l, r), query(2 * in + 1, m + 1, j, l, r));
}

void update(int in, int i, int j, int pos, int v) {
    if (j < pos || i > pos) return;
    if (i == j) {
        st[in].sum = v;
        return;
    }
    int m = (i + j) / 2;
    update(2 * in, i, m, pos, v);
    update(2 * in + 1, m + 1, j, pos, v);
    st[in] = merge(st[2 * in], st[2 * in + 1]);
}

void go() {

    cin >> n;
    forn (i, n) {
        cin >> A[i + 1];
    }
    
    cin >> m;
    
    vector<dquery> Q(m);
    forn (i, m) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].i = i;
    }

    sort(all(Q));

    int lstr = 1;

    int cur = A[1];
    B[cur] = 1;
    update(1, 1, n, B[cur], 1);

    forn (i, m) {
        int l = Q[i].l;
        int r = Q[i].r;
        int idx = Q[i].i;
        
        while (lstr <= r) {
            cur = A[lstr];
            update(1, 1, n, B[cur], 0);
            B[cur] = lstr;
            update(1, 1, n, B[cur], 1);
            lstr++;
        }

        C[idx] = query(1, 1, n, l, r).sum;
    }

    forn (i, m) {
        cout << C[i] << ln;
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