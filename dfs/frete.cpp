/**
 * É passado um grafo com valores entre suas ligações e queremos achar o caminho mais barato entre a primeira e última cidade e imprimir esse valor
 */

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define loop(i,a,n) for(int i=a; i < n; i++)
#define input(x) for (auto &it : x) cin >> it
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef long double ld;
typedef vector<pair<int, int>> ver_val;
typedef vector<ver_val> graph_val;

const int INF = 0x3f3f3f3f;

vector<int> minVals; // menor valor do vértice 1 até o vértice em cada indice
graph_val paths;

void findMinVals(int g=0) {
    for (auto path : paths[g]) {
        const int val = minVals[g] + path.s;
        if (minVals[path.f] > val) {
            minVals[path.f] = val;
            findMinVals(path.f);
        }
    }
}

int getMinPath() {
    minVals = vector<int>(paths.size(), INF);
    minVals[0] = 0;
    findMinVals();
    return minVals.back();
}

int main() { _
    int n, m;
    cin >> n >> m;

    paths = graph_val(n, ver_val());

    int a, b, c;
    for (uint32_t i {0}; i < m; ++i) {
        cin >> a >> b >> c;
        paths[a - 1].emplace_back(b - 1, c);
        paths[b - 1].emplace_back(a - 1, c);
    }

    cout << getMinPath() << endl;

    return 0;
}