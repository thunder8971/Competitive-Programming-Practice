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
template <typename T>
int sz(T &a) {
    return int(a.size());
}

int n, c;
void go() {
    
    vector<int> v(n);
    forn(i, n) {
        cin >> v[i];
    }
    vector<int> pf(n + 1, 0);
    forn(i, n) {
        pf[i + 1] = pf[i] + v[i];
        pf[i + 1] %= c;
    }
    vector<int> lst(c, -1);
    lst[0] = 0;
    forn(i, n) {
        if (lst[pf[i + 1]] != -1) {
            forsn(j, lst[pf[i + 1]], i + 1) {
                cout << j + 1 << " ";
            }
            cout << endl;
            return;
        }
        lst[pf[i + 1]] = i + 1;
    }
    assert(false);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin >> c >> n){
        if (n == 0 && c == 0) {
            break;
        }
        go();
    }
    return 0;
}