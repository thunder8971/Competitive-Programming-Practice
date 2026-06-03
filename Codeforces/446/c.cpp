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

const ll MOD = 1e9 + 9;
const int MAX = 3e5 + 5;

struct vec {
    ll x, y;
    vec() {
        x = y = 0;
    }
    vec(ll x, ll y) {
        this->x = x % MOD;
        this->y = y % MOD;
    }
    vec operator+(const vec &o) const {
        vec res;
        res.x = (this->x + o.x) % MOD;
        res.y = (this->y + o.y) % MOD;
        return res;
    }
};
struct mat {
    ll a, b, c, d;
    mat(ll x = 0) {
        a = d = x % MOD;
        b = c = 0;
    }
    mat(ll a, ll b, ll c, ll d) {
        this->a = a % MOD;
        this->b = b % MOD;
        this->c = c % MOD;
        this->d = d % MOD;
    }
    mat operator+(const mat &o) const {
        mat res;
        res.a = (this->a + o.a) % MOD;
        res.b = (this->b + o.b) % MOD;
        res.c = (this->c + o.c) % MOD;
        res.d = (this->d + o.d) % MOD;
        return res;
    }
    mat operator*(const mat &a) const {
        mat res;
        res.a = (this->a * a.a + this->b * a.c) % MOD;
        res.b = (this->a * a.b + this->b * a.d) % MOD;
        res.c = (this->c * a.a + this->d * a.c) % MOD;
        res.d = (this->c * a.b + this->d * a.d) % MOD;
        return res;
    }   
    vec operator*(const vec &v) const {
        vec res;
        res.x = (this->a * v.x + this->b * v.y) % MOD;
        res.y = (this->c * v.x + this->d * v.y) % MOD;
        return res;
    }
};

struct node {

    vec sum;
    vec lazy;
    node() {
        sum = vec(0, 0);
        lazy = vec(0, 0);
    }

    node operator+(const node &o) const {
        node res;
        res.sum = (this->sum + o.sum);
        return res;
    }

};

vec V = vec(1, 0);
vec B[MAX];
mat A[MAX];
mat pfA[MAX];
node st[4 * MAX];

void pre() {

    A[0] = mat(1);
    A[1] = mat(1, 1, 1, 0);
    pfA[0] = mat(1);
    forsn (i, 2, MAX) {
        A[i] = A[i - 1] * A[1];
    }
    forsn (i, 1, MAX) {
        pfA[i] = pfA[i - 1] + A[i];
    }

}

void build(int it, int l, int r) {
    if (l == r) {
        st[it].sum = B[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * it, l, m);
    build(2 * it + 1, m + 1, r);
    st[it].sum = st[2 * it].sum + st[2 * it + 1].sum;
}

void apply(int it, int len, vec C) {
    st[it].sum = st[it].sum + (pfA[len - 1] * C);
    st[it].lazy = st[it].lazy + C;
}

void propagate(int it, int l, int r) {
    
    if (st[it].lazy.x == 0 && st[it].lazy.y == 0) {
        return;
    }

    if (l == r) {
        st[it].lazy = vec(0, 0);
        return;
    }

    int m = (l + r) / 2;
    int lft = m - l + 1;
    int rgt = r - m;
    
    vec C = st[it].lazy;

    apply(2 * it, lft, C);
    apply(2 * it + 1, rgt, A[lft] * C);

    st[it].lazy = vec(0, 0);
}

node query(int it, int l, int r, int a, int b) {
    propagate(it, l, r);
    if (r < a || l > b) {
        return node();
    }
    if (a <= l && r <= b) {
        propagate(it, l, r);
        return st[it];  
    }
    int m = (l + r) / 2;
    return query(2 * it, l, m, a, b) + query(2 * it + 1, m + 1, r, a, b);
}

void update(int it, int l, int r, int a, int b) {
    propagate(it, l, r);
    if (r < a || l > b) {
        return;
    }
    if (a <= l && r <= b) {

        vec C = A[l - a] * V;
        apply(it, r - l + 1, C);

        return;
    }
    int m = (l + r) / 2;
    update(2 * it, l, m, a, b);
    update(2 * it + 1, m + 1, r, a, b);
    st[it].sum = st[2 * it].sum + st[2 * it + 1].sum;
}

void go() {
    
    pre();

    int n, m;
    cin >> n >> m;

    forn (i, n) {
        cin >> B[i + 1].x;
    }

    build(1, 1, n);

    forn (i, m) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            update(1, 1, n, a, b);
        } else {
            cout << query(1, 1, n, a, b).sum.x << endl;
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