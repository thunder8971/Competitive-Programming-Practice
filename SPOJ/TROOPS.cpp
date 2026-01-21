#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define dforn(i, n) for (int i = int(n)-1; i >= 0; i--)
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define dforsn(i, s, n) for (int i = int(n)-1; i >= int(s); i--)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define endl '\n' 
template <typename T>
int sz(T &a) {
    return int(a.size());
}

const int MAX = 100 + 5;

void go() {
    int n;
    cin >> n;
    vector<piii> v;
    forn(i, n) {
        int ci, ti, si;
        cin >> ci >> ti >> si;
        v.push_back({ti, {ci, si}});
    }
    sort(all(v));
    vector<int> cnt(MAX, 0);
    int tot = 0;
    forn(i, n) {
        int ti = v[i].ff;
        int ci = v[i].ss.ff;
        int si = v[i].ss.ss;
        tot += ci;
        cnt[si] += ci;
        if (tot > ti) {
            int ex = tot - ti;
            forn(j, MAX) {
                if (ex == 0) break;
                int tk = min(cnt[j], ex);
                cnt[j] -= tk;
                ex -= tk;
                tot -= tk;
            }
        }   
    }
    ll ans = 0;
    forn(i, MAX) {
        ans += ll(i) * ll(cnt[i]);
    }
    cout << ans << endl;
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