#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
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

const int INF = 1e9;
const ll LLINF = 2e18;

void go() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    while (m > n) {
        if (m % 2) m++;
        else m /= 2;
        ans++;
    }   
    ans += n - m;
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