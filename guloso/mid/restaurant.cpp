// https://codeforces.com/contest/597/problem/B

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
    int n; cin >> n;
    vector<pair<int, int>> reservas;

    for (int i {0}; i < n; i++) {
        int a, b; cin >> a >> b;
        reservas.emplace_back(b, a);
    }

    sort(reservas.begin(), reservas.end());

    int ans {1}, last = reservas[0].f;

    for (int i {1}; i < n; i++)
        if (reservas[i].s > last) {
            ans++;
            last = reservas[i].f;
        }

    cout << ans << endl;

    return 0;
}
