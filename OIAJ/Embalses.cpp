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
const int MAX = 2e6 + 10;

struct node {

    ll min1 = 0;
    ll min2 = 0;

    node operator+ (node ot) {
        node ret;
        ret.min1 = min(min1, ot.min1); 
        ret.min2 = min(min2, ot.min2); 
        return ret;
    }

};

vector<node> st(4*MAX);

void cl(int it, int l, int r) {
    st[it] = {inf, inf};
    if (l == r) {
        return;
    }
    int m = (l + r) / 2;
    cl(2 * it, l, m);
    cl(1 + 2 * it, m + 1, r);
}

node query(int it, int l, int r, int a, int b) {
    if (r < a || l > b) {
        return {inf, inf};
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
        st[it] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * it, l, mid, x, val);
    update(1 + 2 * it, mid + 1, r, x, val);
    st[it] = st[2 * it] + st[1 + 2 * it];
}

ll f(vector<int> &a, ll k) {
    int n = sz(a);
    cl(1 , 0, n - 1);
    vector<ll> pf(n + 1, 0);
    forn(i, n) {
        pf[i + 1] = pf[i] + a[i];
    }
    vector<ll> dp(n + 1, inf);
    dp[0] = 0;
    forn(i, n) {
        
        node val;
        val.min1 = dp[i] + a[i] - pf[i + 1];
        val.min2 = dp[i] + a[i];

        update(1, 0, n - 1, i, val);

        dp[i + 1] = max(0ll, pf[i + 1] - k);

        int aux = upper_bound(pf.begin() + 1, pf.begin() + i + 2, pf[i + 1] - k) - pf.begin() - 1;

        if (aux > 0) {
            ll ob = query(1, 0, n - 1, 0, aux - 1).min1;
            dp[i + 1] = min(dp[i + 1], pf[i + 1] - k + ob);
        }

        if (aux <= i) {
            ll ob = query(1, 0, n - 1, aux, i).min2;
            dp[i + 1] = min(dp[i + 1], ob);
        }

    }
    return dp[n];
}

void go() {

    ll n, k;
    cin >> n >> k;
    vector<int> a(n, 0);
    forn(i, n) {
        cin >> a[i];
    } 
    vector<int> L(n, 0);
    vector<int> R(n, 0);
    L[0] = a[0];
    forsn(i, 1, n) {
        L[i] = max(L[i - 1], a[i]);
    }
    R[n - 1] = a[n - 1];
    dforn(i, n - 1) {
        R[i] = max(R[i + 1], a[i]);
    }
    vector<int> w(n);
    forsn(i, 1, n - 1) {
        w[i] = min(L[i - 1], R[i + 1]);
    }
    vector<int> cur;
    int i = 0;
    ll ans = 0;
    while(i < n) {
        if (a[i] < w[i]) {
            cur.clear();
            int j = i;
            while(j < n && a[j] < w[j]) {
                cur.push_back(w[j] - a[j]);
                j++;
            }
            ans += f(cur, k);
            i = j;
        }
        i++;
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