#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define dforn(i, n) for (int i = int(n)-1; i >= 0; i--)
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define dforsn(i, s, n) for (int i = int(n)-1; i >= int(s); i--)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define endl '\n'
template <typename T>
int sz(const T &x) {
    return int(x.size());
}
void go() {
    int n;
    cin >> n;
    vector<int> v(n);
    forn(i, n) {
        cin >> v[i];
    }
    if(next_permutation(all(v))) {
        forn(i, n) {
            cout << v[i];
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        go();
    }
    return 0;
}