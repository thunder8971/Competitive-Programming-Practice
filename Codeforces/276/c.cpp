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
#define endl '\n' 
const ll INF = 2e18;

void go() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    forn(i, n) {
        cin >> a[i];
    }
    vector<int> fr(n + 1, 0);
    forn(i, q) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        fr[l]++;
        fr[r + 1]--;
    }
    int cur = 0;
    forn(i, n) {
        cur += fr[i];
        fr[i] = cur;
    }
    fr.pop_back();
    sort(all(fr));
    sort(all(a));
    ll ans = 0;
    forn(i, n) {
        ans += ll(fr[i]) * ll(a[i]);
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
}