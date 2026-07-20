#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define dforn(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
#define all(x) x.begin(), x.end()
#define mk make_pair
#define ff first
#define ss second
#define ln '\n'
template <typename T>
int sz(const T &x) {
    return int(x.size());
}

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;

ll summod(ll a, ll b) {
    return (a % MOD + b % MOD) % MOD; 
}

ll minmod(ll a, ll b) {
    return summod(a % MOD, -b % MOD + MOD);
}

ll mulmod(ll a, ll b) {
    return (a % MOD * b % MOD) % MOD;
}

ll binpowmod(ll a, ll b) {
    ll ret = 1;
    while (b > 0) {
        if (b % 2) {
            ret = mulmod(ret, a);
        }
        a = mulmod(a, a);
        b /= 2;
    }
    return ret;
}

ll divmod(ll a, ll b) {
    return mulmod(a, binpowmod(b, MOD - 2));
}

ll B[MAX], C[MAX];

void go() {

    ll n, k;
    cin >> n >> k;

    ll ans = 0;

    dforsn(i, 1, k + 1) {
        
        ll g = i;
        ll cnt = binpowmod(k / g, n);

        ll aux = 2*g;
        while (aux <= k) {
            cnt = minmod(cnt, C[aux]);
            aux += g;
        }

        C[g] = cnt;

        ans = summod(ans, mulmod(g, cnt));

    }

    cout << ans << ln;

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