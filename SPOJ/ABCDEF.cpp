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
int sz(const T &a) {
    return int(a.size());
}

void go() {
    int n;
    cin >> n;
    vector<int> v(n);
    forn(i, n) {
        cin >> v[i];
    }
    unordered_map<int, int> mp;
    for (auto a : v) {
        for (auto b : v) {
            for (auto c : v) {
                mp[a * b + c]++;
            }
        } 
    }    
    ll ans = 0;
    for (auto d : v) {
        if (d == 0) {
            continue;
        }
        for (auto e : v) {
            for (auto f : v) {
                ans += mp[d * (e + f)];
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    go();
    return 0;
}