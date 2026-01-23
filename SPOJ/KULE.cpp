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

bool flag = false;
string query(vector<int> &p, vector<int> &q) {
    int k = sz(p);
    cout << "WEIGHT " << k;
    forn(i, k) {
        cout << " " << p[i];
    }
    forn(i, k) {
        cout << " " << q[i];
    }
    cout << endl;
    string ret;
    cin >> ret;
    if (flag) {
       ret = ret == "RIGHT" ? "LEFT" : "RIGHT";
    }
    return ret;
}
vector<int> test(vector<int> &v) {
    int n = sz(v);
    if (n == 1) {
        return v;
    }
    if (n == 2) {
        vector<int> p = {v[0]};
        vector<int> q = {v[1]};
        if (query(p, q) == "LEFT") {
            return {v[0]};
        } else {
            return {v[1]};
        }
    }
    int k = n / 3;
    vector<int> p[3];
    forn(i, n) {
        p[i / k].push_back(v[i]);
    }
    string res = query(p[0], p[1]);
    if (res == "LEFT") {
        return test(p[0]);
    } else if (res == "RIGHT") {
        return test(p[1]);
    }
    return test(p[2]);
}

void go() {
    
    int n;
    cin >> n;
    vector<int> v;
    forn(i, n) {
        v.push_back(i + 1);
    }

    int k = n / 3;
    vector<int> p[3];
    forn(i, n) {
        p[i / k].push_back(v[i]);
    }
    vector<int> ans;
    string res = query(p[0], p[1]);
    if (res == "EQUAL") {
        if ( query(p[0], p[2]) == "LEFT" ) {
            flag = true;
        } 
        ans = p[2];
    } else if (res == "LEFT") {
        if (query(p[0], p[2]) == "EQUAL") {
            flag = true;
            ans = p[1];
        } else {
            ans = p[0];
        }
    } else if (res == "RIGHT") {
        if (query(p[1], p[2]) == "EQUAL") {
            flag = true;
            ans = p[0];
        } else {
            ans = p[1];
        }
    }
    ans = test(ans);
    cout << "ANSWER " << (flag ? "-" : "") << ans[0] << endl;
 
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    go();
    return 0;
}