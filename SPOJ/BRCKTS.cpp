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
int n, m;
string s;
struct node{
    int lf = ninf;
    int tot = 0;
    node operator + (const node &o) const {
        node res;

        res.tot = tot + o.tot;
        res.lf = min(lf, tot + o.lf);

        return res;
    }
};
node nul = node{inf, inf};
int A[MAX];
vector<node> st(4 * MAX);
void build(int it, int l, int r) {
    if (l == r) {
        st[it].lf = A[l];
        st[it].tot = A[l];
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

void update(int it, int l, int r, int pos) {
    if (r < pos || l > pos) return;
    if (l == r) {
        A[pos] = -A[pos];
        st[it] = node{A[pos], A[pos]};
        return;
    }
    int m = (l + r) / 2;
    update(2 * it, l, m, pos);
    update(2 * it + 1, m + 1, r, pos);
    st[it] = st[2 * it] + st[2 * it + 1];
}


void go() {

    cin >> n >> s;

    forn (i, n) {
        A[i + 1] = s[i] == '(' ? 1 : -1;
    }
      
    build(1, 1, n);
    
    cin >> m;

    forn (i, m) {
        int k;
        cin >> k;
        if (k == 0) {
            bool ans = st[1].tot == 0 && st[1].lf >= 0;
            cout << (ans ? "YES" : "NO") << ln;
        } else {
            update(1, 1, n, k);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tt = 10;
    // cin >> tt;
    forn (tc, tt) {
        cout << "Test " << tc + 1 << ":" << ln;
        go();
    }
    return 0;
}