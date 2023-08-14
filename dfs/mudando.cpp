/**
 * É passado um array de n posições.
 *
 * Devemos retornar um array reduzido, por exemplo {54, 32, 233, 4, 92, 8} -> {3, 2, 5, 0, 4 1}
 */

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define loop(i,a,n) for(int i=a; i < n; i++)
#define input(x) for (auto& it : x) cin >> it
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1);

int main() { _
    uint32_t n;
    cin >> n;
    vector<int> v(n);
    vector<int> sorted_v(n);

    for (uint32_t i {0}; i < n; ++i) {
        cin >> v[i];
        sorted_v[i] = v[i];
    }

    sort(sorted_v.begin(), sorted_v.end());

    map<int, uint32_t> menor_i;

    for (uint32_t i {0}; i < n; ++i)
        menor_i[sorted_v[i]] = i;

    for (uint32_t i {0}; i < n; ++i)
        v[i] = (int) menor_i[v[i]];

    for (uint32_t i {0}; i < n; ++i)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}