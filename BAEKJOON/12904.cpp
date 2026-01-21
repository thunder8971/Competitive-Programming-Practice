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
template <typename T>
int sz(T &a) {
    return int(a.size());
}

const ll INF = 2e18;

void go() {
    string s, t;
    cin >> s >> t;
    int n = sz(s), m = sz(t);
    int l = 0, r = m - 1, dir = 1;
    forn(i, m - n) {
        int j = dir == 1 ? r : l;
        char c = t[j];
        if(dir == 1) r--;
        else l++;
        if (c == 'B') dir *= -1;
    }

    int aux = dir == 1 ? l : r;
    forn(i, n) {
        if(t[aux] != s[i]) {
            cout << 0 << endl;
            return;
        }
        aux += dir;
    }
    cout << 1 << endl;
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