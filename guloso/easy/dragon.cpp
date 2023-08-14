// https://codeforces.com/contest/1337/problem/B

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define input(x) for (auto &it : x) cin >> it
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;

int main() { _
    int t; cin >> t;

    for (int i {0}; i < t; i++) {
        // hp / 2 + 10 < hp => hp < 20
        int x, n, m; cin >> x >> n >> m;
        for ( ; x > 20 && n; n--)
            x = x / 2 + 10;

        for ( ; x > 0 && m; m--)
            x -= 10;

        cout << (x > 0 ? "NO" : "YES") << endl;
    }

    return 0;
}
