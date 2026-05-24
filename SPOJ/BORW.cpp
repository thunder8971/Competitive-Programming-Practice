#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define ln '\n'
template <typename T>
int sz(const T &x) {
    return int(x.size());
}


const int MAX = 2e2 + 5;
int n;
int DP[MAX][MAX][MAX];
int A[MAX];

int f(int i, int j, int k) {

    if (i > n) {
        return 0;
    }

    if (DP[i][j][k] != -1) {
        return DP[i][j][k];
    }

    int ret = f(i + 1, j, k);
    
    if ( A[i] > A[j] ) {
        ret = max(ret, f(i + 1, i, k) + 1);
    }

    if ( A[i] < A[k] ) {
        ret = max(ret, f(i + 1, j, i) + 1);
    }

    return  DP[i][j][k] = ret;

}

void go() {

    forn (i, n) {
        cin >> A[i + 1];
    }

    forn (i, n + 2) {
        forn (j, n + 2) {
            forn (k, n + 2) {
                DP[i][j][k] = -1;
            }
        }
    } 

    A[0] = 0;

    A[n + 1] = 1e9;

    int ans = n - f(1, 0, n + 1);

    cout << ans << ln;
              
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin >> n) {
        if (n == -1) {
            break;
        }
        go();
    }

    return 0;
}