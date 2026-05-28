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

const int MAX = 1000 + 5; 
int n, m;
string A[MAX], B[MAX];

struct trie {
    map<char, trie> child;

    void insert(const string &s, int i = 0) {
        if (i == sz(s)) {
            return;
        }
        child[s[i]].insert(s, i + 1);
    }

    int nodes() const {
        int res = 1;
        for (auto &p : child) {
            res += p.ss.nodes();
        }
        return res;
    }

};

int cnt[2][26];
void build(trie &t, int id, int h = 0) {
    for (auto &p : t.child) {
        if (h > 0) {
            cnt[id][p.ff - 'a']++;
        }
        build(p.ss, id, h + 1);
    }
}

void go() {
    
    memset(cnt, 0, sizeof cnt);

    forn (i, n) {
        cin >> A[i];
    }

    forn (i, m) {
        cin >> B[i];
    }

    trie t[2];
    forn (i, n) {
        t[0].insert(A[i]);
    } 
    forn (i, m) {
        reverse(all(B[i]));
        t[1].insert(B[i]);
    }

    forn (i, 2) {
        build(t[i], i);
    }

    ll ans = (t[0].nodes() - 1) * 1ll * (t[1].nodes() - 1);
    for (char c = 'a'; c <= 'z'; c++) {
        ans -= (cnt[0][c - 'a'] * 1ll * cnt[1][c - 'a']);
    }

    cout << ans << ln;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        go();
    }
    return 0;
}