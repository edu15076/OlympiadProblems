// https://www.beecrowd.com.br/judge/pt/problems/view/2243

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

/**
 * O maior triângulo possível em uma coluna é o menor dos valores para o maior triângulo possível nas colunas adjacentes
 * somado a 1, isso se a coluna for maior do que esse valor. Caso o contrário, a o maior triângulo possível tem o
 * tamanho da coluna.
 */
int maxPossibleTriangleAt(vector<int>& a, int pos) {
    const int minAdj = min(a[pos - 1], a[pos + 1]) + 1;
    return min(a[pos], minAdj);
}

/**
 * Assumimos primeiro que o maior valor em cada coluna é o seu tamanho e logo corrigimos isso pegando o valor semi correto
 * pela função maxPossibleTriangleAt, o valor é semi correto pois o valor da coluna de maior índice está incorreto, mas
 * ainda assim o valor está correto em relação aos tamanhos das colunas e às colunas de menor índice. A correção completa
 * se da quando fazemos o processo inverso, pois corrigimos o valor para a coluna de maior índice.
 */

int main() { _
    int n; cin >> n;
    vector<int> maxIso(n + 2);
    maxIso[0] = maxIso[n + 1] = 0;
    int first; cin >> first;

    for (int i {1}; i < n; i++) {
        cin >> maxIso[i + 1];
        maxIso[i] = maxPossibleTriangleAt(maxIso, i);
    }

    int maxHeight = 1;

    for (int i {n + 1}; i > 0; i--) {
        maxIso[i] = maxPossibleTriangleAt(maxIso, i);
        maxHeight = max(maxIso[i], maxHeight);
    }

    cout << maxHeight << endl;

    return 0;
}
