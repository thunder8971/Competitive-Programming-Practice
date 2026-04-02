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

struct task {
    ll l, r, p;
    bool operator<(const task &other) const {
        if (r == other.r) {
            return l < other.l;
        }
        return r < other.r;
    }
};

void go() {
    int n;
    cin >> n;
    vector<task> v(n);
    forn (i, n) {
        cin >> v[i].l >> v[i].r >> v[i].p;
    }
    sort(all(v));

    vector<ll> dp(n);
    dp[0] = v[0].p;
    forsn (i, 1, n) {
        int l = 0, r = i - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (v[m].r < v[i].l) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        
        if (v[l].r < v[i].l) {
            dp[i] = max(dp[l] + v[i].p, v[i].p);
        } else {
            dp[i] = v[i].p;
        }
        dp[i] = max(dp[i], dp[i - 1]);
    }
    cout << *max_element(all(dp)) << ln;

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