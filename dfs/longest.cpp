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
const int MAX = 1e4+10;

vector<vector<int>> g(MAX);
vector<int> dist(MAX, -1);

void dfs(int v) {
    for (auto f : g[v])
        if (dist[f] == -1) {
            dist[f] = dist[v] + 1;
            dfs(f);
        }
}

int main() { _
    int n, m; cin >> n; m = n - 1;

    for (int i {0}; i < m; ++i) {
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dist[0] = 0;
    dfs(0);

    int max_pos {-1}, max_dist {-1};

    for (int i {0}; i < n; i++)
        if (dist[i] > max_dist) {
            max_pos = i;
            max_dist = dist[i];
        }

    dist = vector<int>(n, -1);

    dist[max_pos] = 0;
    dfs(max_pos);

    cout << *max_element(dist.begin(), dist.end()) << endl;

    return 0;
}
