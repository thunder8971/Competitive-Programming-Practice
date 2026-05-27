#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define dforn(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define ln '\n'
template <typename T>
int sz(const T &x) {
    return int(x.size());
}

const int MAX = 1e7 + 5;
ll A[MAX], B[MAX], C[MAX];

void go() {

    ll n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    A[1] = x;
    forsn(i, 2, n + 1) {
        A[i] = (A[i - 1] % c * a % c + b) % c;
    }

    ll ans = 0;
    forsn (i, 1, n + 1) {
        if ( (i - 1) % k == 0) {
            B[i] = A[i];
        } else {
            B[i] = B[i - 1] | A[i];
        }
    }
    dforsn (i, 1, n + 1) {
        if (i == n || i % k == 0) {
            C[i] = A[i];
        } else {
            C[i] = C[i + 1] | A[i];
        }
    }

    forsn (r, k, n + 1) {
        int l = r - k + 1;
        ans = ans ^ (C[l] | B[r]);
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