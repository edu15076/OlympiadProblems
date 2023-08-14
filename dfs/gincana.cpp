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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<bool> v(1024, false);
vector<vector<uint32_t>> g(1024, vector<uint32_t>());

void dfs(uint32_t a) {
    v[a] = true;

    for (auto af : g[a])
        if (!v[af])
            dfs(af);
}

int main() { _
    uint32_t n, m;
    cin >> n >> m;

    for (uint32_t k {0}; k < m; ++k) {
        uint32_t i, j; cin >> i >> j; i--; j--;
        g[i].push_back(j);
        g[j].push_back(i);
    }

    uint32_t times {0};
    for (uint32_t i {0}; i < n; ++i)
        if (!v[i]) {
            dfs(i);
            times++;
        }

    cout << times << endl;

    return 0;
}
