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

const int MAX = 2e5 + 5;
const int inf = 1e9;
const int ninf = -1e9;
const ll linf = 1e18;
const ll nlinf = -1e18;

ll A[MAX], B[MAX];

void go() {
    
    int n, a, b;
    cin >> n >> a >> b; 
    
    forn (i, n) {
        cin >> A[i + 1];
    }
    
    forn (i, n) {
        B[i + 1] = B[i] + A[i + 1];
    }
    
    ll ans = nlinf;
    
    deque<ll> dq;
    dq.push_back(0);
        
    forsn (i, a, n + 1) {
        ll l = max(0, i - b), r = i - a;
        while (!dq.empty() && B[dq.back()] >= B[r]) {
            dq.pop_back();
        }
        dq.push_back(r);
        while (!dq.empty() && dq.front() < l) {
            dq.pop_front(); 
        }
        ans = max(ans, B[i] - B[dq.front()]);
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